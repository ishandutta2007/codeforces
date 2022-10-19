#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<double,double> pd;
typedef vector<pd> vpd;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

int rango(vvi& rocas, int i1, int j1, int i2, int j2){
    int res = rocas[i2][j2];
    if(i1 > 0) res -= rocas[i1-1][j2];
    if(j1 > 0) res -= rocas[i2][j1-1];
    if(i1 > 0 and j1 > 0) res += rocas[i1-1][j1-1];
    return res;
}

int col(vvi& rocas, int i1, int i2, int j){
    int res = rocas[i2][j] - rocas[i1-1][j];
    if(j > 0) res -= rocas[i2][j-1] - rocas[i1-1][j-1];
    return res;
}

int fil(vvi& rocas, int i, int j1, int j2){
    int res = rocas[i][j2] - rocas[i][j1-1];
    if(i > 0) res -= rocas[i-1][j2] - rocas[i-1][j1-1];
    return res;
}

void c(){
    int n,m;
    cin>>n>>m;
    vector<string> t(n);
    F0(i,n) cin>>t[i];
    if(n == 1 and m == 1){
        cout<<1<<'\n';
        return;
    }
    vvi rocas(n,vi(m));
    F0(i,n) F0(j,m) if(t[i][j] == 'R') rocas[i][j]++;
    F0(i,n) F0(j,m) {
        if(i > 0) rocas[i][j] += rocas[i-1][j];
        if(j > 0) rocas[i][j] += rocas[i][j-1];
        if(i > 0 and j > 0) rocas[i][j] -= rocas[i-1][j-1];
    }

    vvll R(n,vll(m)),D(n,vll(m));
    vvll sR(n+1,vll(m+1)),sD(n+1,vll(m+1));
    F0R(i,n) F0R(j,m){
        if(i == n-1) D[i][j] = 0;
        else
            D[i][j] = sR[i+1][j] - sR[n-col(rocas,i+1,n-1,j)][j];
        if(j == m-1) R[i][j] = 0;
        else
            R[i][j] = sD[i][j+1] - sD[i][m-fil(rocas,i,j+1,m-1)];
        if(i == n-1 and j == m-1)
            D[i][j] = R[i][j] = 1;

        D[i][j] %= mod;
        if(D[i][j] < 0) D[i][j] += mod;
        R[i][j] %= mod;
        if(R[i][j] < 0) R[i][j] += mod;
        sD[i][j] = (sD[i][j+1] + D[i][j]) % mod;
        sR[i][j] = (sR[i+1][j] + R[i][j]) % mod;
    }
    int res = (D[0][0] + R[0][0]) % mod;
    cout<<res<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    c();
    return 0;
}