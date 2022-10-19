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
typedef vector<vpi> vvpi;
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
    string s;
    cin>>s;
    int n = s.size();
    vi unos(n+1);
    F0(i,n) {
        if(s[i] == '1') unos[i+1] = unos[i]+1;
        else unos[i+1] = unos[i];
    }

    int res = INF;
    F0(l,n+1){
        REP(r,l,n){
            int resi = (r-l) - (unos[r] - unos[l]);
            if(unos[l] > 0) continue;
            if(0 < unos[n] - unos[r]) continue;
            mini(res,resi);
        }
    }
    cout<<res<<'\n';
}

void b(){
    ll n,g,b;
    cin>>n>>g>>b;
    ll res = (n+1)/2;
    res /= g;
    res *= (g+b);
    res += ((n+1)/2)%g;
    if(((n+1)/2)%g == 0) res -= b;
    cout<<max(res,n)<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) b();
    return 0;
}