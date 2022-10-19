#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
using ll = long long;
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
#define forall(it,s) for(auto it = s.begin(); it != s.end();it++)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define todo(v) v.begin(),v.end()
const int mod = 998244353;
const ll INF  = 1e18;
const double eps = 0.00000001;

int n;
vi a;
const int N = 9e7;
int s[N+1];
int magic = 400;

int probar(int m){
    int res = 0;
    F0(i,n){
        int b = a[i] - m*i;
        b += 4e7;
        s[b]++;
        maxi(res,s[b]);
    }
    F0(i,n){
        int b = a[i] - m*i;
        b += 4e7;
        s[b]--;
    }
    return res;
}

void E(){
    F0(i,N+1) s[i] = 0;
    cin>>n;
    a = vi(n);
    F0(i,n) cin>>a[i];
    int junto = 1;
    for(int m = -magic; m <= magic; m++){
        maxi(junto, probar(m));
    }
    F0(i,n){
        for(int j = i+1; j < min(n,i+magic); j++){
            if((a[j]-a[i])%(j-i)) continue;
            int m = (a[j]-a[i])/(j-i);
            m += 4e7;
            s[m]++;
            maxi(junto,s[m]+1);
        }
        for(int j = i+1; j < min(n,i+magic); j++){
            if((a[j]-a[i])%(j-i)) continue;
            int m = (a[j]-a[i])/(j-i);
            m += 4e7;
            s[m]--;
        }
    }
    cout<<n-junto<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    E();
}