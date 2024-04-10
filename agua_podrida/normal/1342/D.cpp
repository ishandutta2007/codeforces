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
#define REP(i,a,b) for(ll i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e17
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 998244353

void aa(){
    ll x,y,a,b;
    cin>>x>>y>>a>>b;
    if(x > y) swap(x,y);
    ll res = (y-x)*a;
    res += min(2*a,b)*x;
    cout<<res<<'\n';
}

bool todosIguales(string s){
    int i = 0;
    while(i < s.size() and s[i] == s[0]) i++;
    return i == s.size();
}

void bb(){
    string s;
    cin>>s;
    if(todosIguales(s)) cout<<s<<'\n';
    else {
        F0(i,s.size()) cout<<"10";
        cout<<'\n';
    }
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

void c(){
    ll a,b;
    ll l,r;
    int q;
    cin>>a>>b>>q;
    ll caca;
    if(a < b) swap(a,b);
    ll objetivo = b/gcd(a,b);
    while(q--){
        cin>>l>>r;
        ll res = 0;
        ll completos = (r-l+1)/(objetivo*a);
        res += completos*a;
        ll rp = r - completos * objetivo * a;
        ll x = l;
        while(x <= rp){
            if((x%a)%b == x%b) res++;
            x++;
        }
        res = (r-l+1)-res;
        cout<<res<<' ';
    }
    cout<<'\n';
}

void d(){
    int n,k;
    cin>>n>>k;
    vi m(n);
    F0(i,n) cin>>m[i];
    vi c(k+1);
    F1(i,k) cin>>c[i];
    sort(todo(m));
    reverse(todo(m));
    int ans = 0;
    int mayores = 0;
    F1R(tam,k){
        while(m[mayores] == tam) mayores++;
        maxi(ans,(mayores+c[tam]-1)/c[tam]);
    }
    vvi res(ans);
    F0(i,n){
        res[i%ans].pb(m[i]);
    }
    cout<<ans<<'\n';
    F0(i,ans){
        cout<<res[i].size()<<' ';
        F0(j,res[i].size()) cout<<res[i][j]<<' ';
        cout<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../output.txt","w",stdout);
    d();
    return 0;
}