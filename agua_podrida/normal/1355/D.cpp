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
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 998244353

ll minDig(ll a){
    ll res = 10;
    while(a > 0){
        mini(res,a%10);
        a /= 10;
    }
    return res;
}

ll maxDig(ll a){
    ll res = 0;
    while(a > 0){
        maxi(res,a%10);
        a /= 10;
    }
    return res;
}

void a(){
    ll a,k;
    cin>>a>>k;
    k--;
    while(k > 0 and minDig(a) != 0){
        a += minDig(a) * maxDig(a);
        k--;
    }
    cout<<a<<'\n';
}

void c(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll res = 0;
    ll suman = (c-b+1)*(b-a+1);
    REP(z,a+b,c-1){
        if(a+b <= z and z <= min(a+c,b+b)) suman -= (ll) z - a - b + 1;
        if(min(a+c,b+b) < z and z <= max(a+c,b+b)) suman -= min(b-a,c-b)+1;
        if(max(a+c,b+b) < z and z <= b+c) suman -= c+b-z+1;
    }
    REP(z,c,d){
        if(a+b <= z and z <= min(a+c,b+b)) suman -= (ll) z - a - b + 1;
        if(min(a+c,b+b) < z and z <= max(a+c,b+b)) suman -= min(b-a,c-b)+1;
        if(max(a+c,b+b) < z and z <= b+c) suman -= c+b-z+1;
        res += suman;
    }
    cout<<res<<'\n';
}

void d(){
    int n;
    ll s;
    cin>>n>>s;
    if(n > s/2) {
        cout<<"NO\n";
        return;
    }
    vll a(n);
    F0(i,n-1) {
        a[i] = 2;
    }
    a.back() = s-2*(n-1);
    cout<<"YES\n";
    F0(i,n) cout<<a[i]<<' ';
    cout<<'\n';
    cout<<1<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    d();
    return 0;
}