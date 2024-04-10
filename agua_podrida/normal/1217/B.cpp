#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
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
ll mod = 998244353;

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
    ll str,inte,exp;
    cin>>str>>inte>>exp;
    if(str + exp <= inte) cout<<"0\n";
    else if(exp + inte < str) cout<<exp+1<<'\n';
    else {
        ll k = inte + exp - str;
        k = k/2;
        ll res = exp - k;
        cout<<res<<'\n';
    }
}

void b(){
    int n,x;
    cin>>n>>x;
    vi d(n);
    vi h(n);
    F0(i,n) cin>>d[i]>>h[i];
    int maxDif = -1;
    F0(i,n) maxi(maxDif,d[i]-h[i]);
    int maxD = -1;
    F0(i,n) maxi(maxD,d[i]);
    if(maxD < x and maxDif <= 0) {
        cout<<-1<<'\n';
        return;
    }
    if(maxD >= x){
        cout<<1<<'\n';
        return;
    }
    x -= maxD;
    int res = 1;
    res += (x+maxDif-1) / maxDif;
    cout<<res<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) b();
    return 0;
}