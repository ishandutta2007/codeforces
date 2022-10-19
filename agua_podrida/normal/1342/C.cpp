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

void c(){
    ll a,b,l,r;
    int q;
    cin>>a>>b>>q;
    if(a < b) swap(a,b);
    vll hasta(a*b);
    ll x = 1;
    while(x < a*b){
        hasta[x] = hasta[x-1];
        if((x%a)%b != (x%b)%a) hasta[x]++;
        x++;
    }
    ll tam,periodos;
    while(q--){
        cin>>l>>r;
        tam = r-l+1;
        periodos = tam/(a*b);
        ll res = periodos*hasta[a*b-1];
        r -= periodos*a*b;
        x = l;
        while(x <= r){
            if(x%a == 0){
                if((x%a)%b != (x%b)%a) res += min(r-x+1,a);
                x += a;
            }
            else {
                if((x%a)%b != (x%b)%a) res++;
                x++;
            }
        }
        cout<<res<<' ';
    }
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) c();
    return 0;
}