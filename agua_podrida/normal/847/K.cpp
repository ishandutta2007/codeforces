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
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)

void k(){
    int n,a,b,k,f;
    cin>>n>>a>>b>>k>>f;
    vector<pair<string,string>> c;
    map<pair<string,string>,int> m;
    string u,v;
    int acum = 0;
    F0(i,n) {
        cin>>u>>v;
        if(i == 0 or c.back().second != u) m[{min(u,v),max(u,v)}] += a;
        else m[{min(u,v),max(u,v)}] += b;
        c.pb({u,v});
    }

    for(auto it : m) acum += it.second;

    vi coso;
    for(auto it : m) coso.pb(it.second);

    sort(todo(coso));

    while(k > 0 and !coso.empty() and coso.back() > f){
        acum += f;
        acum -= coso.back();
        coso.pop_back();
        k--;
    }

    cout<<acum<<'\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../evolution/evolution-11-common-endings.in","r",stdin);
    //freopen("../output.txt","w",stdout);
    k();
    return 0;
}