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
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 4e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

ll f(ll x, ll y, ll z){
    ll res = 0;
    res += (x-y)*(x-y);
    res += (x-z)*(x-z);
    res += (z-y)*(z-y);
    return res;
}

void resolver(vll& a, vll& b, vll& c, ll& res){
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < a.size()){
        while(j < b.size() and b[j] < a[i]) j++;
        if(j == b.size()) break;
        while(k < c.size() and c[k] < (a[i]+b[j])/2){
            mini(res,f(a[i],b[j],c[k]));
            k++;
        }
        if(k < c.size()) mini(res,f(a[i],b[j],c[k]));
        k--;
        if(k < 0) k = 0;
        i++;
    }
}

void b(){
    int nr,ng,nb;
    cin>>nr>>ng>>nb;
    vll r(nr);
    F0(i,nr) cin>>r[i];
    sort(todo(r));
    vll g(ng);
    F0(i,ng) cin>>g[i];
    sort(todo(g));
    vll b(nb);
    F0(i,nb) cin>>b[i];
    sort(todo(b));

    ll res = INF;
    resolver(r,g,b,res);
    resolver(r,b,g,res);
    resolver(g,r,b,res);
    resolver(g,b,r,res);
    resolver(b,r,g,res);
    resolver(b,g,r,res);

    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../c2.in","r",stdin);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) b();
    return 0;
}