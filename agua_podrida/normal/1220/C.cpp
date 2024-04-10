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
    string s;
    cin>>s;
    int enes = 0;
    int zetas = 0;
    F0(i,n){
        if(s[i] == 'z') zetas++;
        if(s[i] == 'n') enes++;
    }
    while(enes--) cout<<"1 ";
    while(zetas--) cout<<"0 ";
    cout<<endl;
}

int gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

int supergcd(vll& v){
    int res = gcd(v[0],v[1]);
    F1(i,v.size()-2){
        res = gcd(res,v[i+1]);
    }
    return res;
}

ll sqrtn(ll n){
    ll hi = n+1;
    ll lo = 0;
    while(lo + 1 != hi){
        ll mid = (lo+hi)/2;
        if(mid*mid <= n) lo = mid;
        else hi = mid;
    }
    return lo;
}

void b(){
    int n;
    cin>>n;
    vvll M(n,vll(n));
    F0(i,n) F0(j,n) cin>>M[i][j];
    vll res(n);
    res[0] = (supergcd(M[0]));
    F1(i,n-1){
        res[i] = M[0][i] / res[0];
    }
    if(res[1] * res[2] != M[1][2]){
        ll factor = M[1][2] / res[1] / res[2];
        factor = sqrtn(factor);
        res[0] /= factor;
        F1(i,n-1) res[i] *= factor;
    }
    F0(i,n) cout<<res[i]<<' ';
    cout<<endl;
}

void c(){
    string s;
    cin>>s;
    char minimo = 'z';
    F0(k,s.size()){
        if(s[k] <= minimo) cout<<"Mike\n";
        else cout<<"Ann\n";
        mini(minimo,s[k]);
    }
}

int main(){
    c();
    return 0;
}