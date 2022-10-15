#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

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
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 205;

ll dp[maxn][maxn];
bool bad[maxn][maxn];

struct pt{
    int x,y;
    pt operator - (pt b) {
        return {x-b.x,y-b.y};
    }
    int operator * (pt b){
        ll dot = x * (ll)b.x + y * (ll)b.y;
        if (dot>0)return 1;
        if (dot<0)return -1;
        return 0;
    }
    int operator ^ (pt b) {
        ll cross = x * (ll)b.y - y * (ll)b.x;
        if (cross>0)return 1;
        if (cross<0)return -1;
        return 0;
    }
    bool operator != (pt b){
        return x!=b.x||y!=b.y;
    }
};
inline bool its(pt &a,pt&b,pt&c,pt&d){
    int A = ((b-a)^(c-a)), B = ((b-a)^(d-a));
    if (a!=c && !A && ((a-c)*(b-c))<0) return 1;
    if (b!=d && !B && ((a-d)*(b-d))<0) return 1;
    return A*B < 0 &&
        ((c-d)^(a-d))*((c-d)^(b-d)) < 0;
}
inline bool nits(pt &a,pt&b,pt&c,pt&d){
    int A = ((b-a)^(c-a)), B = ((b-a)^(d-a));
    return A*B <= 0 &&
        ((c-d)^(a-d))*((c-d)^(b-d)) <= 0;
}
int n;
inline int f(int x){
    if (x>=n)return x-n;
    return x;
}
signed main(){
    IOS();
    cin>>n;
    vector<pt> v;
    for (int i = 0; i<n; i++) {
        int x,y; cin>>x>>y;
//        bug(x+900,y-424);
        v.pb({x*2,y*2});
    }
//    return 0;
    for (int i = 0; i<n; i++) {
        for (int j = i+2; j<n; j++) {
            if (i==0 && j==n-1) continue;

            for (int k = 0; k<n; k++) {
                if ((its(v[i], v[j], v[k],  v[f(k+1)])) ) {
                    bug(i,j,k,f(k+1));
                    bad[i][j] = 1; break;
                }
            }
            if (!bad[i][j]) {
                pt mid = {(v[i].x+v[j].x)/2,(v[i].y+v[j].y)/2};
                pt lol = {mid.x+1,20000001};
                bool fine = 0;
                for (int k = 0; k<n; k++) {
                    if (nits(mid,lol,v[k],v[f(k+1)])) {
                        fine^=1;
                    }
                }
                if (!fine) {
                    bug(i,j);
                    bad[i][j] =1;
                }
            }
            bad[j][i] = bad[i][j];
        }
    }

    for (int df = 1; df < n; df ++) {
        for (int l = 0; l<n; l++) {
            int r = f(l+df);
            if (bad[l][r]) continue;
            if (df <= 2) {
                dp[l][r] = 1; continue;
            }
            for (int k = l+1; k<l+df; k++) {
                dp[l][r] += dp[l][f(k)] * dp[f(k)][r];
                dp[l][r] %= mod;
            }
            bug(l,r,dp[l][r]);
            if (df == n-1) {
                cout<<dp[l][r]<<endl; return 0;
            }
        }
    }

    cout<<dp[1][0]<<endl;
}
/*
8
1 1
2 0
2 -2
1 -3
-1 -3
-2 -2
-2 0
-1 1
*/