#include <bits/stdc++.h>
#pragma GCC optimize("O3","unroll-loops")
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; --i)
#define REP1(i,n) FOR(i,1,n+1)
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
#define Vec array<ull,20>
#define Mat array<Vec, 20>

const int maxn = 20;
int n, m, q;
bool cat[maxn][maxn];

Vec A;
inline int f(int a, int b){return a*m+b;}
void mul(Mat &c, Mat a, Mat b){ // c = a*b;
    REP(i,20) REP(j,20) {
        c[i][j]=0;
        REP(k,20){
            c[i][j]+=a[i][k] * b[k][j];

        }
        c[i][j]%=mod;
    }
}
void move(int T){
    Mat pM;
    REP(i,20)REP(j,20)pM[i][j]=0;
    REP(i,n) REP(j,m){
        if (cat[i][j]) continue;
        pM[f(i,j)][f(i,j)]=1;
        if (i) pM[f(i,j)][f(i-1,j)]=1;
        if (j) pM[f(i,j)][f(i,j-1)]=1;
        if (i<n-1) pM[f(i,j)][f(i+1,j)]=1;
        if (j<m-1) pM[f(i,j)][f(i,j+1)]=1;
    }
    Mat M;
    REP(i,20)REP(j,20) M[i][j] = i==j;
    while (T>0){
        if (T%2==1){
            mul(M,M,pM);
        }
        mul(pM,pM,pM);
        T/=2;
    }
    Vec nA;
    REP(i,20){
        nA[i]=0;
        REP(j,20){
            nA[i]=(nA[i]+A[j]*M[i][j])%mod;
        }
    }
    A=nA;
}

signed main(){
    IOS();
    cin>>n>>m>>q;
    fill(ALL(A),0);
    A[0]=1;
    int prv = 1;
    REP(tmpcnt, q){
        int TP; cin>>TP;
        int x,y,t; cin>>x>>y>>t; --x; --y;

        if (TP == 1){
            move(t-prv); prv=t;
            cout<<A[f(x,y)]<<endl;
        }
        if (TP == 2){
            move(t-prv); prv=t;
            cat[x][y]=1; A[f(x,y)]=0;
        }
        if (TP == 3){
//            --t;
            move(t-prv); prv=t;
            cat[x][y]=0;
        }
    }

}