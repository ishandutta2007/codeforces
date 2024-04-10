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
#define mod 1000000007

void a(){
    int n;
    cin>>n;
    ll a = 0;
    ll b = 0;
    ll uno = 1;
    a += (uno<<n);
    b += (uno<<(n-1));
    F1(i,n/2-1) a += (uno<<i);
    REP(i,n/2,n-2) b += (uno<<i);
    cout<<a-b<<'\n';
}

void eliminarRepetidos(vi& a){
    vi res;
    res.pb(a[0]);
    F1(i,a.size()-1){
        if(a[i] != res.back()) res.pb(a[i]);
    }
    a = res;
}

void b(){
    int n,k;
    cin>>n>>k;
    vi a(n);
    F0(i,n) cin>>a[i];
    sort(todo(a));
    eliminarRepetidos(a);
    if(a.size() > k){
        cout<<"-1\n";
        return;
    }
    cout<<n*k<<'\n';
    F0(j,n){
        F0(i,a.size()){
            cout<<a[i]<<' ';
        }
        F0(i,k-a.size()) cout<<a[0]<<' ';
    }
    cout<<'\n';
}

void c(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vi ap(26);
    F0(i,n) ap[(int) s[i] - (int) 'a']++;
    int i = 0;
    while(ap[i] == 0) i++;
    if(ap[i] == n){
        int cant = (n+k-1)/k;
        F0(j,cant) cout<<s[0];
        cout<<'\n';
        return;
    }

    if(ap[i] < k){
        int suma = ap[i];
        while(suma < k){
            i++;
            suma += ap[i];
        }
        char b = (char) ((int) 'a' + i);
        cout<<b<<'\n';
        return;
    }

    if(ap[i] == k){
        int j = i+1;
        while(ap[j] == 0) j++;
        if(ap[i] + ap[j] == n){
            cout<<(char) ((int) 'a' + i);
            int cant = (ap[j]+k-1)/k;
            F0(l,cant) cout<<(char) ((int) 'a' + j);
            cout<<'\n';
            return;
        }
    }

    ap[i] -= k-1;
    F0(i,26){
        while(ap[i]--) cout<<(char) ((int) 'a' + i);
    }
    cout<<'\n';
}

void d(){
    ll n;
    cin>>n;
    ll suma = 1;
    ll cant = 1;
    int d = 0;
    while(suma < n){
        cant *= 2;
        suma += cant;
        d++;
    }

    cout<<d<<'\n';
    vll res(d);
    ll cota = 1;
    suma = d+1;
    F0(i,d){
        res[i] = min(cota,(n-suma)/(d-i));
        suma += res[i]*(d-i);
        cota += res[i];
    }
    F0(i,d) cout<<res[i]<<' ';
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