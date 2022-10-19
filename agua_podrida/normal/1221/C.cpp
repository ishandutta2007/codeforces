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
#define F first
#define S second
#define INF 100000000
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

void a(){
    int n;
    cin>>n;
    vi s(n);
    F0(i,n) cin>>s[i];
    sort(todo(s));
    while(!s.empty() and s.back() > 2048) s.pop_back();
    int suma = 0;
    int i = 0;
    while(suma < 2048 and i < s.size()) {
        suma += s[i];
        i++;
    }
    if(suma >= 2048) cout<<"YES\n";
    else cout<<"NO\n";
}

void b(){
    int n;
    cin>>n;
    F0(i,n){
        F0(j,n){
            if((i+j)%2 == 0) cout<<"W";
            else cout<<"B";
        }
        cout<<'\n';
    }
}

void c(){
    ll c,m,x;
    cin>>c>>m>>x;
    ll res = min(c,m);
    mini(res,x);
    c -= res;
    m -= res;
    x -= res;
    if(c > 0 and m > 0){
        res += min((c+m)/3,min(c,m));
    }
    cout<<res<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) c();
    return 0;
}