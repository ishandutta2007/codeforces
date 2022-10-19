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
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it : s)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e9
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define sq(a) (a)*(a)
#define teamSize(t) ((t)<t4 ? 4 : ( (t)<t4+t3 ) ? 3 : 2 )
#define R real
#define I imag
const ll mod = 1e9+7;

int f(string& s, int n){
    vvvi dp(2,vvi(2,vi(n+2,n)));
    int a = 0, b = 0;
    if(s[0] == 'R') a = 1;
    if(s[1] == 'R') b = 1;
    dp[a][b][1] = 0;
    REP(i,2,n+1){
        F0(a,2) {
            F0(b,2){
                F0(c,2){
                    if(a == b and b == c) continue;
                    int suma = 0;
                    if((c == 1) != (s[i] == 'R')) suma = 1;
                    mini(dp[b][c][i],dp[a][b][i-1] + suma);
                }
            }
        }
    }
    a = 0, b = 0;
    if(s[0] == 'R') a = 1;
    if(s[1] == 'R') b = 1;
    return dp[a][b][n+1];
}

void d(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    char prim = s[0];
    char sec = s[1];

    int res = n;
    F0(b,4){
        if(b%2) s[0] = 'R';
        else s[0] = 'L';
        if(b/2) s[1] = 'R';
        else s[1] = 'L';
        s.pb(s[0]);
        s.pb(s[1]);
        int resi = f(s,n);
        s.pop_back();
        s.pop_back();
        if(s[0] != prim) resi++;
        if(s[1] != sec) resi++;
        mini(res,resi);
    }
    cout<<res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) d();
}