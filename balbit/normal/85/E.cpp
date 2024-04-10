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

const int maxn = 5005;

int col[maxn];
int x[maxn], y[maxn];
int d[maxn][maxn];
int n, M;
bool dfs(int v) {
    for (int u = 0; u<n; ++u) {
        if (d[v][u] > M) {
            if (col[u] == -1) {
                col[u] = col[v] ^ 1;
                if (!dfs(u)) return 0;
            }else{
                if (col[u] != col[v] ^ 1) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

signed main(){
    IOS();
    cin>>n;
//    vector<pii> v(n);
    for (int i = 0; i<n; i++) {
        cin>>x[i]>>y[i];
    }
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; ++j) {
            d[i][j] = abs(x[i] - x[j]) + abs(y[i]-y[j]);
        }
    }
    int l = 0, r = 100002;
    int nof = 0;
//    M = 1;

    while (l!=r) {
        memset(col,-1,sizeof col);
        M = l+r>>1;
        bool B = 1;
        for (int i = 0; i<n; i++) {
            if (col[i] == -1) {
                col[i] = 0;
                if (!dfs(i)) {
                    B = 0;
                    break;
                }
            }
        }
        if (!B) {
            l = M+1;
        }else{
            r = M;
        }
    }
    cout<<l<<endl;
    memset(col,-1,sizeof col);
    M = l;
    for (int i = 0; i<n; i++) {
        if (col[i] == -1) {
            col[i] = 0;
            nof++;
            dfs(i);
        }
    }
    cout<<mpow(2,nof)<<endl;
}