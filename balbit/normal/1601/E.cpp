#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define y1 zck_is_king
#define pii pair<int, int>
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
const ll inf = 1ll<<60;
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

const int maxn = 6e5+100;

int a[maxn];
int ans[maxn];
vector<pii> qu[maxn]; // {left point, index}

ll seg[maxn*4],tg[maxn*4];

void push(int o, int l, int r) {
    if (tg[o]) {
        seg[o] += tg[o] * (r-l+1);
        if (l != r) {
            tg[o*2] += tg[o];
            tg[o*2+1] += tg[o];
        }
        tg[o] = 0;
    }
}

void MO(int L, int R, int v, int o = 1, int l=0, int r = maxn-1) {
    push(o,l,r);
    if (l > R || r < L) return;
    if (l >= L && r <= R) {
        tg[o]+=v;
        push(o,l,r);
        return;
    }
    int mid = (l+r)/2;
    MO(L,R,v,o*2,l,mid);
    MO(L,R,v,o*2+1,mid+1,r);
    seg[o] = seg[o*2] + seg[o*2+1];
}

ll QU(int L, int R, int o=1, int l=0, int r=maxn-1) {
    if (l > R || r < L) return 0;
    push(o,l,r);
    if (l >= L && r <= R) return seg[o];
    int mid = (l+r)/2;
    return QU(L,R,o*2,l,mid) + QU(L,R,o*2+1,mid+1,r);
}

int qq[maxn*2+5];

void moo(int p, int v) {
    for (qq[p += maxn]=v; p>1; p>>=1) {
        qq[p>>1] = min(qq[p], qq[p^1]);
    }
}

int rmq(int l, int r) {
    // from [l, r)
    int re = 1e9+10;
    for (l+=maxn, r +=maxn; l<r; l>>=1, r >>=1) {
        if (l&1) MN(re, qq[l++]);
        if (r&1) MN(re, qq[--r]);
    }
    return re;
}

int modpos[maxn];
int biggestmod[maxn]; // biggest of this modulus
vector<pair<int, pii> > stk[maxn]; // value, range on seg tree

signed main(){
    IOS();

    int n,q,k; cin>>n>>q>>k;
    REP(i,n) {
        cin>>a[n-i-1];
    }
    REP(i,n){
        moo(i, a[i]);
        biggestmod [i%k] = i;
    }
    REP(i,k) {
        modpos[i+1] = modpos[i];
        modpos[i+1] += biggestmod[i] / k + 2;
    }
    REP(i,q) {
        int x,y; cin>>x>>y; --x; --y;
        x=n-x-1;
        y=n-y-1;
        swap(x,y);
        qu[y].pb({x,i});
    }

    // on the segment tree, modulus m is placed on position modpos[m]

    REP(i,n) {
        int M = i % k;
        int offset = modpos[M];
        bug(i, M, offset);


        ll valhere = stk[M].empty()? inf: rmq(i-k+1,i+1); // remember [l,r)

        while (!stk[M].empty() && stk[M].back().f >= valhere) {
            MO(stk[M].back().s.f, stk[M].back().s.s, -stk[M].back().f);
            stk[M].pop_back();
        }

        if (i/k != 0) if (stk[M].empty() || stk[M].back().s.s != i/k+offset-1) {
            stk[M].pb({valhere, {stk[M].empty()?(offset) : (stk[M].back().s.s + 1), i/k+offset-1}});
            MO(stk[M].back().s.f, stk[M].back().s.s, stk[M].back().f);
        }

        stk[M].pb({a[i], {i/k+offset, i/k+offset}});
        MO(stk[M].back().s.f, stk[M].back().s.s, stk[M].back().f);

        for (pii p : qu[i]) {
            int l = p.f, id = p.s;
            int cnt = (i-l) / k; // probably, might need to check
            bug (l,i,"eats",cnt);
            ans[id] = QU(offset + i/k - cnt, offset + i/k);
            bug(id, ans[id], offset+i/k-cnt, offset+i/k);
        }

//        if (i == 4) {
//            bug("FOUR!!!");
//            for (auto e : stk[M]) {
//                cout<<e.f<<' '<<e.s.f<<' '<<e.s.s<<endl;
//            }
//            bug(QU(0,0));
//            bug(QU(1,1));
//            bug(QU(2,2));
//            bug(QU(0,2));
//        }
    }

    REP(i,q) {
        cout<<ans[i]<<endl;
    }

}