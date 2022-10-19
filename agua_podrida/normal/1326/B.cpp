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
ll mod = 998244353;

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
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

void a(){
    int n;
    cin>>n;
    if(n == 1) {
        cout<<-1<<'\n';
        return;
    }
    string s;
    s.pb('2');
    F0(i,n-1) s.pb('3');
    cout<<s<<'\n';
}

void b(){
    int n;
    cin>>n;
    vi b(n);
    F0(i,n) cin>>b[i];
    vi x(n);
    vi a(n);
    a[0] = b[0];
    x[0] = 0;
    F1(i,n-1){
        x[i] = max(x[i-1],a[i-1]);
        a[i] = b[i] + x[i];
    }
    F0(i,n) cout<<a[i]<<' ';
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    b();
    return 0;
}