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
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

int n;
ll p;

int a[1000050];
int b[1000050];

ll pot(ll a, int exp){
    if(exp == 0) return 1;
    ll b = pot(a,exp/2);
    b *= b;
    b %= mod;
    if(exp%2 == 1) b *= a;
    return b%mod;
}

void sumara(int ki, int& maximo){
    int i = ki;
    a[i]++;
    while(a[i] == p){
        a[i] = 0;
        a[i+1]++;
        i++;
    }
    if(i >= maximo){
        while(i >= ki and a[i] == b[i]) i--;
        if(i < ki) maximo = -1;
        else maximo = i;
    }
}

void sumarb(int ki, int& maximo){
    int i = ki;
    b[i]++;
    while(b[i] == p){
        b[i] = 0;
        b[i+1]++;
        i++;
    }
    if(i >= maximo){
        while(i >= ki and a[i] == b[i]) i--;
        if(i < ki) maximo = -1;
        else maximo = i;
    }
}

void bb(){
    cin>>n>>p;
    vi k(n);
    F0(i,n) cin>>k[i];
    if(p == 1){
        if(n % 2 == 1) cout<<"1\n";
        else cout<<"0\n";
        return;
    }

    sort(todo(k));
    reverse(todo(k));

    int maximo = k[0];
    a[maximo] = 1;
    F1(i,n-1){
        if(maximo != -1) sumarb(k[i], maximo);
        else sumara(k[i],maximo);
    }

    ll res = 0;
    F0(i,n){
        F0(j,21){
            if(a[k[i]+j] - b[k[i]+j] != 0) {
                res += (a[k[i]+j] - b[k[i]+j]) * pot(p,k[i]+j);
                res %= mod;
            }
            a[k[i]+j] = 0;
            b[k[i]+j] = 0;
        }
    }

    res += mod;
    res %= mod;
    cout<<res<<'\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) bb();
    return 0;
}