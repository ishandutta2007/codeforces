#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
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
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
ll mod = 1000000007;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

void a(){
    ll n,m;
    cin>>n>>m;
    vll a(n);
    F0(i,n) cin>>a[i];
    ll suma = 0;
    F0(i,n) suma += a[i];
    cout<<min(suma,m)<<'\n';
}

void b(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<pair<string,int>> v;
    v.pb(mp(s,1));
    reverse(todo(s));
    v.pb(mp(s,n));
    reverse(todo(s));
    REP(k,2,n-1){
        string t;
        F0(i,n-k+1) t.pb(s[i+k-1]);
        if((n-k+1)%2 == 0){
            F0(i,k-1) t.pb(s[i]);
        }
        else {
            F0(i,k-1) t.pb(s[k-2-i]);
        }
        v.pb(mp(t,k));
    }
    sort(todo(v));
    cout<<v[0].F<<'\n';
    cout<<v[0].S<<'\n';
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int t; cin>>t;
    while(t--) b();
    return 0;
}