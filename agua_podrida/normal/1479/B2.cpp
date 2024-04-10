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
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 2e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define mod 1000000007

int seg(vi& a){
    int res = 0;
    if(!a.empty()) res++;
    F1(i,(int) a.size()-1){
        if(a[i] != a[i-1]) res++;
    }
    return res;
}

void sinRepetidos(vi& a){
    vi res;
    res.pb(a[0]);
    F1(i,(int) a.size()-1){
        if(a[i] != a[i-1]) res.pb(a[i]);
    }
    a = res;
}

vi dp;
vi sig;

int f(vi& a, int i){
    if(i == a.size()) return 0;
    if(dp[i] == -1){
        if(sig[i] < a.size()) maxi(dp[i],1+f(a,sig[i]));
        if(sig[i-1] < a.size()) maxi(dp[i],1+f(a,sig[i-1]));
        maxi(dp[i],f(a,i+1));
    }
    return dp[i];
}

void b(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    sinRepetidos(a);

    if(a.size() == 1) {
        cout<<1<<'\n';
        return;
    }
    sig = vi(a.size(),-1);
    vi ult(n+1,a.size());
    F0R(i,a.size()){
        sig[i] = ult[a[i]];
        ult[a[i]] = i;
    }
    dp = vi(a.size(),-1);
    int res = f(a,1);
    res = a.size()-res;
    cout<<res<<'\n';
}

int main(){
    b();
}