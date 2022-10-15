#include <bits/stdc++.h>
#define int ll
using namespace std;
#define ll long long
#define y1 zck_is_king
#define pii pair<ll, ll>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define REP(i,n) for (int i = 0; i<n; ++i)
#define RREP(i,n) for (int i = n-1; i>=0; --i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

const int iinf = 1e9+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9+7 ;


void GG(){cout<<"0\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 2e5+5;

int seg[2 * maxn];

void build() {  // build the tree
  for (int i = maxn - 1; i > 0; --i) seg[i] = max(seg[i<<1] , seg[i<<1|1]);
}

void modify(int p, int value) {  // set value at position p
    for (seg[p += maxn] = value; p > 1; p >>= 1) seg[p>>1] = max(seg[p] , seg[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
    ll res = -iinf;
    for (l += maxn, r += maxn; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, seg[l++]);
        if (r&1) res = max(res, seg[--r]);
    }
    return res;
}


namespace gtmax{
    int seg[2 * maxn];

    void build() {  // build the tree
      fill(seg, seg+2*maxn,-iinf);
    }

    void modify(int p, int value) {  // set value at position p
        for (seg[p += maxn] = value; p > 1; p >>= 1) seg[p>>1] = max(seg[p] , seg[p^1]);
    }

    int query(int l, int r) {  // sum on interval [l, r)
        ll res = -iinf;
        for (l += maxn, r += maxn; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = max(res, seg[l++]);
            if (r&1) res = max(res, seg[--r]);
        }
        return res;
    }
};

namespace gtmin{
    int seg[2 * maxn];

    void build() {  // build the tree
      fill(seg, seg+2*maxn,iinf);
    }

    void modify(int p, int value) {  // set value at position p
        for (seg[p += maxn] = value; p > 1; p >>= 1) seg[p>>1] = min(seg[p] , seg[p^1]);
    }

    int query(int l, int r) {  // sum on interval [l, r)
        ll res = iinf;
        for (l += maxn, r += maxn; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = min(res, seg[l++]);
            if (r&1) res = min(res, seg[--r]);
        }
        return res;
    }
};


int L[2][19][maxn], R[2][19][maxn]; // down/up, power ,
int a[maxn];

signed main(){
    IOS();

    fill(seg, seg+maxn*2, -iinf);
    gtmin::build(); gtmax::build();

    int n; cin>>n;
    REP(i,n) {
        cin>>a[i]; --a[i];
        gtmin::modify(i, a[i]);
        gtmax::modify(i, a[i]);
    }

    REP(i,n) {
        L[0][0][i] = query(0,a[i]); if (L[0][0][i] == -iinf) L[0][0][i] = -1;
        L[1][0][i] = query(a[i]+1,n); if (L[1][0][i] == -iinf) L[1][0][i] = -1;
        modify(a[i], i);
    }

    fill(seg, seg+maxn*2, -iinf);

    RREP(i,n) {
        R[0][0][i] = -query(0,a[i]); if (R[0][0][i] == iinf) R[0][0][i] = n;
        R[1][0][i] = -query(a[i]+1,n); if (R[1][0][i] == iinf) R[1][0][i] = n;
        modify(a[i], -i);
    }

    REP(i, n) {
        bug(L[0][0][i], L[1][0][i]);
        bug(R[0][0][i], R[1][0][i]);
    }

    REP1(j,19-1) {
        REP(b,2) {
            REP(i,n) {
                    L[b][j][i] = L[b][j-1][i] == -1? -1: L[b][j-1][L[b][j-1][i]];
                    R[b][j][i] = R[b][j-1][i] == n ?  n: R[b][j-1][R[b][j-1][i]];

            }
        }
    }

    ll re = 0;

    REP(i,n) {
        // bs for first bad point
        int bl = i, br = n;
        while (bl != br) {
            int go = (bl + br) / 2;
            // test if go is bad
            vector<int> c(2,0);
            REP(d,2) {
                int at = go;
                RREP(j,19) {
                    if (L[d][j][at] >= i) {
                        at = L[d][j][at];
                        c[d] += (1<<j);
                    }
                }
            }
            int sg = c[0] + c[1];
            bug(sg, go-i);
            if (sg == go-i) {
                // this point is still good
                bl = go+1;
            }else{
                br=go;
            }
        }
        int BAD = bl;
        if (BAD >= n) {
            // all good!
            re += n-i;
            continue;
        }

        bug(i, BAD);

        int oL = L[0][0][BAD-1], oR = L[1][0][BAD-1];
        int voL = oL==-1? -1 : a[oL];
        int voR = oR==-1? iinf : a[oR];
        assert(a[BAD] < voL || a[BAD] > voR);
        int up, dw;
        if (a[BAD] < voL) {
            dw = BAD; up = oL;

            bl = BAD+1, br = n;
            while (bl!=br) {
                int md = (bl + br)/2;
                if (gtmax::query(BAD+1, md+1) > voL) {
                    br = md;
                }else {
                    bl = md+1;
                }
            }
            up = bl;
        }else if (a[BAD] > voR) {
            up = BAD; dw = oR;
            bl = BAD+1, br = n;
            while (bl!=br) {
                int md = (bl + br)/2;
                if (gtmin::query(BAD+1, md+1) < voR) {
                    br = md;
                }else {
                    bl = md+1;
                }
            }
            dw = bl;
        }else assert(0);

        bug(up, dw);

        bl = BAD, br = n;
        // where can i get to???
        while (bl != br) {
            int mid = (bl + br) / 2;


            vector<int> c(2,0);
            REP(d,2) {
                int at = d==0?dw : up;
                if (mid >= at) {
                    ++c[d];
                    RREP(j,19) {
                        if (R[d][j][at] <= mid) {
                            at = R[d][j][at];
                            c[d] += (1<<j);
                        }
                    }
                }
            }
            int took = c[0] + c[1];

            if (took == mid - BAD + 1) {
                bl = mid + 1;
            }else {
                br = mid;
            }
        }
        --bl;
        bug (bl);
        re += bl - i + 1;
    }
    cout<<re<<endl;
}