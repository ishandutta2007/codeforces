#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
using ll = long long;
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
#define forall(it,s) for(auto it = s.begin(); it != s.end();it++)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define todo(v) v.begin(),v.end()
const int mod = 998244353;
const ll INF  = 1e18;
const double eps = 0.00000001;

int n,m;
string s;

vvi coso,nuevo;

void F(){
    cin>>n>>s;
    m = (1<<n);
    coso = vvi(m);
    F0(i,m) coso[i].pb(s[i] - 'a');
    F0(it,n){
        nuevo = vvi(coso.size()/2,vi((1<<(it+1))));
        vector<pair<pi,pi>> pares;
        F0(i,nuevo.size()){
            F0(j,coso[0].size()){
                pares.pb({{coso[2*i][j],coso[2*i+1][j]},{i,j}});
                pares.pb({{coso[2*i+1][j],coso[2*i][j]},{i,j+(1<<it)}});
            }
        }
        sort(todo(pares));
        int id = 0;
        int x,y;
        F0(i,pares.size()){
            if(i != 0 and pares[i].first != pares[i-1].first) id++;
            tie(x,y) = pares[i].second;
            nuevo[x][y] = id;
        }
        swap(coso,nuevo);
    }
    int j = 0;
    while(coso[0][j] != 0) j++;
    string t;
    F0(i,m) t += s[i^j];
    cout<<t<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    F();
}