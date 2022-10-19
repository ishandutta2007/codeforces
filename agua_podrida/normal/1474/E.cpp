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

void e(){
    int n;
    cin>>n;
    if(n == 2){
        cout<<"1\n2 1\n1\n2 1\n";
        return;
    }
    if(n == 3){
        cout<<"5\n2 3 1\n2\n1 3\n3 2\n";
        return;
    }
    ll seconds = 0;
    vll p(n+1);
    p[1] = n;
    p[n] = 2;
    REP(i,2,n/2-1) p[i] = i+1;
    p[n/2] = n-1;
    p[n/2+1] = 1;
    REP(i,n/2+2,n-1) p[i] = i-1;

    vpll s;
    REP(i,2,n/2) s.pb({i,n});
    REPR(i,n,n/2+1) s.pb({i,1});

    for(auto sw : s){
        seconds += (sw.second-sw.first)*(sw.second-sw.first);
    }

    cout<<seconds<<'\n';
    F1(i,n) cout<<p[i]<<' ';
    cout<<'\n'<<n-1<<'\n';
    for(auto sw : s) cout<<sw.first<<' '<<sw.second<<'\n';
}

int main() {
    //freopen("../evolution/evolution-11-common-endings.in","r",stdin);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) e();
    return 0;
}