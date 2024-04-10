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

const int maxn = 1e5+5;

vector<pii> vx, vy;

map<int, vector<pii> > mp;

//bool tst[200][200];

void add(int x, int y, ll dst) {
    bug(x,y,dst);
    mp[x-y].pb({x, x+dst-1});
//    REP(j, min(dst, 20ll)) {
//        tst[x+j][y+j] = 0;
//    }

}

bool get(int x, int y) {
    if (!mp.count(x-y)) return 0;
    vector<pii> & v = mp[x-y];
    auto it = upper_bound(ALL(v), pii{x, (ll)iinf*2});
    if (it == v.begin()) return 0;
    it = prev(it);
//    if (x == 7 && y == 8) {
//        bug(it->f, it->s);
//    }
    if (it->f <= x && it->s >= x) return 1;
    return 0;
}

namespace MXTree{
    int seg[maxn*2];
    void MO(int p, int value) {  // set value at position p
        for (seg[p += maxn] = value; p > 1; p >>= 1) seg[p>>1] = max(seg[p] , seg[p^1]);
    }

    int QU(int l, int r) {  // sum on interval [l, r)
        int res = -iinf;
        for (l += maxn, r += maxn; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = max(res, seg[l++]);
            if (r&1) res = max(res, seg[--r]);
        }
        return res;
    }
}

namespace MNTree{
    int seg[maxn*2];
    void MO(int p, int value) {  // set value at position p
        for (seg[p += maxn] = value; p > 1; p >>= 1) seg[p>>1] = min(seg[p] , seg[p^1]);
    }

    int QU(int l, int r) {  // sum on interval [l, r)
        int res = iinf;
        for (l += maxn, r += maxn; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = min(res, seg[l++]);
            if (r&1) res = min(res, seg[--r]);
        }
        return res;
    }
}

signed main(){
    IOS();
//    REP(i,100) REP(j,100) tst[i][j] = 1;
    int n,m; cin>>n>>m;
    REP(i,n) {
        int x,y; cin>>x>>y;
        vx.pb({x,y});

//        tst[x][y] = 0;
    }

//    tst[0][0] = 0;

    vy = vx;
    sort(ALL(vx));
    sort(ALL(vy), [&](pii a, pii b){return a.s < b.s;});
    REP(i,n) {
        MXTree::MO(i, vx[i].f - vx[i].s);
        MNTree::MO(i, vy[i].f - vy[i].s);
    }

    int nx = 1, ny = 1;
    // find the next bad node >= (nx, ny)
    int itx = 0, ity = 0;



    while (1) {
        ll whenx = inf;
        while (itx < SZ(vx)) {
            if (vx[itx].f < nx ) {
                ++itx; continue;
            }
            break;
        }

        {
            int l = itx, r = n;
            while (l!=r) {
                int mid = (l+r)/2;
                if (MXTree::QU(itx, mid+1) > nx - ny) {
                    r = mid;
                }else{
                    l = mid+1;
                }
            }
            if (l != n) {
                whenx = vx[l].f - nx;
            }
        }

        ll wheny = inf;
        while(ity < SZ(vy)) {
            if (vy[ity].s < ny) {
                ++ity; continue;
            }
            break;
        }

        {
            int l = ity, r = n;
            while (l!=r) {
                int mid = (l+r)/2;
                if (MNTree::QU(ity, mid+1) < nx - ny) {
                    r = mid;
                }else{
                    l = mid+1;
                }
            }
            if (l != n) {
                wheny = vy[l].s - ny;
            }
        }

        bug(whenx, wheny);

        if (wheny == inf && whenx == inf) {
//            bug(nx, ny, "to inf!!");
            add(nx, ny, iinf);
            break;
        }

        int smol = min(whenx, wheny);
        if (smol != 0) {
            add(nx, ny, smol);
        }

        nx += smol; ny += smol;

        if (smol == whenx) {
            ++nx;
        }else{
            ++ny;
        }
    }

//    REP(i, 15) REP(j,15) {
//        cout<<(tst[i][j]?'.':'0')<<" \n"[j==14];
//    }

//    cout<<endl<<endl;
    vx.pb({0,0});
    sort(ALL(vx));

//    REP(i, 15) REP(j,15) {
//        cout<<((binary_search(ALL(vx), pii{i,j}) || get(i,j))?'.':'0')<<" \n"[j==14];
//    }



    REP(tt, m) {
        int a,b; cin>>a>>b;
        if (binary_search(ALL(vx), pii{a,b}) || get(a,b)) {
            cout<<"LOSE"<<endl;
        }else{
            cout<<"WIN"<<endl;
        }
    }
}

/*

*/