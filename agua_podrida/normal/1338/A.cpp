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
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

bool esCreciente(vll& a){
    F1(i,a.size()-1) if(a[i] < a[i-1]) return false;
    return true;
}

bool vale(int k, vll a){
    ll uno = 1;
    ll sumaMaxima = (1<<k)-1;
    a.back() += sumaMaxima;
    F0R(i,a.size()-1) {
        if(a[i] > a[i+1])
            return false;
        a[i] = min(a[i]+sumaMaxima,a[i+1]);
    }
    return true;
}

void a(){
    int n;
    cin>>n;
    vll a(n);
    F0(i,n) cin>>a[i];

    if(esCreciente(a)) {
        cout<<"0\n";
        return;
    }
    int lo = 0;
    int hi = 32;
    while(lo+1 != hi){
        int mid = (lo+hi)/2;
        if(vale(mid,a)) hi = mid;
        else lo = mid;
    }
    cout<<hi<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../c2.in","r",stdin);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) a();
    return 0;
}