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
#define mod 998244353

bool vale(vi a , vi b, int n){
    if(b[0] > a[0])
        return false;
    F0(i,n-1){
        if(a[i] > a[i+1]) return false;
        if(b[i] > b[i+1]) return false;
        if(b[i+1]-b[i] > a[i+1]-a[i]) return false;
    }
    return true;
}

void a(){
    int n;
    cin>>n;
    vi a(n),b(n);
    F0(i,n) cin>>a[i]>>b[i];
    if(vale(a,b,n)) cout<<"YES\n";
    else cout<<"NO\n";
}

void b(){
    int n;
    ll x;
    cin>>n>>x;
    vll a(n);
    F0(i,n) cin>>a[i];
    sort(todo(a));
    reverse(todo(a));
    ll res = 0;
    ll suma = 0;
    while(res < n and suma+a[res] >= x*(res+1)){
        suma += a[res];
        res++;
    }
    cout<<res<<'\n';
}

void c(){
    int n;
    cin>>n;
    vll a(n),b(n);
    F0(i,n) cin>>a[i]>>b[i];
    int primero = 0;
    ll descuento = min(a[0],b[n-1]);
    F1(i,n-1){
        if(min(a[i],b[i-1]) < descuento){
            descuento = min(a[i],b[i-1]);
            primero = i;
        }
    }

    int i = primero;
    ll res = 0;
    do{
        res += a[i%n];
        a[(i+1)%n] -= b[i%n];
        if(a[(i+1)%n] < 0) a[(i+1)%n] = 0;
        i++;
    }
    while(i%n != primero);
    cout<<res<<'\n';
}

void d(){
    ll n,l,r;
    cin>>n>>l>>r;
    ll pos = 1;
    ll base = 1;
    while(base < n and pos+2*(n-base) < l){
        pos += 2*(n-base);
        base++;
    }
    ll num = base;
    ll siguiente = base+1;
    while(pos <= r){
        if(pos >= l) cout<<num<<' ';
        if(num == base){
            num = siguiente;
            siguiente++;
            if(num == n){
                base++;
                siguiente = base+1;
                if(base == num) base = 1;
            }
        }
        else {
            num = base;
        }
        pos++;
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
    while(t--) d();
    return 0;
}