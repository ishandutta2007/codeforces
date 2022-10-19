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
ll mod = 998244353;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
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
#define F first
#define S second
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

void a(){
    int n;
    cin>>n;
    if(n == 1) {
        cout<<-1<<'\n';
        return;
    }
    string s;
    s.pb('2');
    F0(i,n-1) s.pb('3');
    cout<<s<<'\n';
}

void b(){
    int n;
    cin>>n;
    vi b(n);
    F0(i,n) cin>>b[i];
    vi x(n);
    vi a(n);
    a[0] = b[0];
    x[0] = 0;
    F1(i,n-1){
        x[i] = max(x[i-1],a[i-1]);
        a[i] = b[i] + x[i];
    }
    F0(i,n) cout<<a[i]<<' ';
    cout<<'\n';
}

void c(){
    int n,k;
    cin>>n>>k;
    vi p(n);
    F0(i,n) cin>>p[i];
    ll maxV = 0;
    F1(i,n) if(i > n-k) maxV += (ll) i;
    ll res = 1;
    int i = 0;
    while(p[i] <= n-k) i++;
    int ultVisto = i;
    i++;
    while(i < n){
        while(i < n and p[i] <= n-k) i++;
        if(i == n) break;
        res *= (ll) (i - ultVisto);
        res %= mod;
        ultVisto = i;
        i++;
    }
    cout<<maxV<<' '<<res<<'\n';
}

bool esPalindromo(string& s, int l, int r){
    while(l < r and s[l] == s[r]){
        l++; r--;
    }
    return l >= r;
}

void d(){
    string s;
    cin>>s;
    int n = s.size();
    int l = 0;
    int r = n-1;
    while(l < r and s[l] == s[r]){
        l++; r--;
    }
    int maxL = l-1;
    REP(i,l,r){
        if(esPalindromo(s,l,i)) maxL = i;
    }
    int maxR = r+1;
    REPR(i,r,l){
        if(esPalindromo(s,i,r)) maxR = i;
    }
    string res;
    if(maxL - l > r - maxR){
        F0(i,maxL+1) res.pb(s[i]);
        REP(i,r+1,n-1) res.pb(s[i]);
    }
    else{
        F0(i,l) res.pb(s[i]);
        REP(i,maxR,n-1) res.pb(s[i]);
    }
    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    c();
    return 0;
}