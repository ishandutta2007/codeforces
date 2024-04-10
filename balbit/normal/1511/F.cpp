#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
const ll mod = 998244353;


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

const int maxn = 40+5;

int n,m;
int to[maxn][26];
bool isend[maxn];
int from[maxn]; // what was my last letter?
int IT = 1;

const int IDK = 402;

typedef array<ll, IDK> vec;
typedef array<vec, IDK> mat;
vector<int> nxt[maxn];

int ID[maxn][maxn];
    int JT = 0;
mat M;
vec hi;

void mul(mat a, mat b, mat &c) {
    REP(i,JT) REP(j,JT) {
        c[i][j] = 0;
        REP(k,JT) {
            c[i][j] += a[i][k] * b[k][j];
            c[i][j] %= mod;
        }
    }
}

void mulv(vec a, mat b, vec &c) {
    REP(i,JT) {
        c[i] = 0;
        REP(j,JT) {
            c[i] += a[j] * b[j][i];
            c[i] %= mod;
        }
    }
}

signed main(){
    IOS();
    cin>>n>>m;
    memset(to, -1, sizeof to);
    memset(from, -1, sizeof from);

    REP(ttt,n) {
        string s; cin>>s;
        int at = 0;
        REP(i, SZ(s)) {
            int  c= s[i] - 'a';

            if (to[at][c] == -1) {
                from[IT] = c;
                to[at][c] = IT++;
            }
            at = to[at][c];
        }
        isend[at] = 1;
    }

    memset(ID, -1, sizeof ID);
    REP(i, IT) {
        REP(j,i+1) {
            if (from[i] == from[j] || i == 0 || j ==0) {
                ID[i][j] = ID[j][i] = JT;
                ++JT;
            }
        }
    }

    bug(IT);

    REP(i, IT) {
        REP(j,i+1) {
            if (from[i] == from[j] || i == 0 || j ==0) {
                REP(c, 26) {
                    int I = to[i][c];
                    int J = to[j][c];
                    if (I == -1 || J == -1) continue;
                    M[ID[i][j]][ID[I][J]]++;
                    if (isend[I]) M[ID[i][j]][ID[0][J]]++;
                    if (isend[J]) M[ID[i][j]][ID[I][0]]++;
                    if (isend[J] && isend[I]) M[ID[i][j]][ID[0][0]]++;
                }
            }
        }
    }
//    return 0;

    hi[ID[0][0]] = 1;

    REP(i, 30) {
        if (m & (1<<i)) {
            mulv(hi, M, hi);
        }
        mul(M,M,M);
    }
    cout<<hi[0]<<endl;


}