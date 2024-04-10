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
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

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
#define INF 1000000000000000000
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

void a(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    int i = 0;
    int res = 0;
    while(i < n){
        int j = i+1;
        while(j < n and a[j] == a[j-1]+1) j++;
        maxi(res,j-i-2);
        i = j;
    }
    if(a[0] == 1){
        int i = 1;
        while(i < n and a[i] == a[i-1]+1) i++;
        maxi(res,i-1);
    }
    if(a.back() == 1000){
        int i = n-2;
        while(i >= 0 and a[i] == a[i+1]-1) i--;
        maxi(res,n-2-i);
    }
    cout<<res<<'\n';
}

map<ll,int> factorizar(ll n){
    map<ll,int> res;
    ll d = 2;
    while(d*d <= n){
        while(n%d == 0){
            res[d]++;
            n /= d;
        }
        d++;
    }
    if(n > 1) res[n]++;
    return res;
}

bool casoEspecial(map<ll,int> f){
    int a = f.begin()->second;
    forall(it,f) if(it->second != a) return false;
    forall(it,f){
        while(it->second % 2 == 0) it->second/=2;
        if(it->second != 1) return false;
    }
    return true;
}

void b(){
    ll n;
    cin>>n;
    map<ll,int> f = factorizar(n);
    int maxF = 0;
    forall(it,f) maxi(maxF,it->second);
    ll res = 1;
    forall(it,f) res *= it->first;
    int res2 = 0;
    while(maxF > 1){
        maxF = (maxF+1)/2;
        res2++;
    }
    if(!casoEspecial(f)) res2++;
    cout<<res<<' '<<res2<<'\n';
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    b();
    return 0;
}