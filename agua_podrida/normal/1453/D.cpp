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
typedef pair<double,double> pd;
typedef vector<pd> vpd;
typedef complex<double> cd;
typedef vector<cd> vcd;

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
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

void a(){
    int n,m;
    cin>>n>>m;
    set<int> s;
    int x;
    while(n--) {
        cin>>x;
        s.insert(x);
    }
    int res = 0;
    while(m--){
        cin>>x;
        if(s.count(x)) res++;
    }
    cout<<res<<'\n';
}

void b(){
    int n;
    cin>>n;
    vll a(n);
    F0(i,n) cin>>a[i];
    if(n == 2) {
        cout<<"0\n";
        return;
    }
    ll dif = 0;
    F0(i,n-1) dif += abs(a[i]-a[i+1]);
    ll res = dif;
    F1(i,n-2) {
        ll resi = dif;
        resi -= abs(a[i-1]-a[i]);
        resi -= abs(a[i+1]-a[i]);
        resi += abs(a[i-1]-a[i+1]);
        mini(res,resi);
    }
    mini(res,dif - abs(a[0]-a[1]));
    mini(res,dif - abs(a[n-1] - a[n-2]));
    cout<<res<<'\n';
}

void c(){
    int n;
    cin>>n;
    vector<string> a(n);
    F0(i,n) cin>>a[i];

    F0(c,10){
        char b = (int) '0' + c;
        int arr = n;
        int ab = 0;
        int izq = n;
        int der = 0;
        F0(i,n){
            F0(j,n){
                if(a[i][j] == b){
                    mini(arr,i);
                    maxi(ab,i);
                    mini(izq,j);
                    maxi(der,j);
                }
            }
        }
        int res = 0;
        F0(i,n){
            F0(j,n){
                if(a[i][j] == b){
                    maxi(res,max(i,n-i-1) * max(der-j,j-izq));
                    maxi(res,max(j,n-j-1) * max(i - arr, ab - i));
                }
            }
        }
        cout<<res<<' ';
    }
    cout<<'\n';
}

void d(){
    ll k;
    cin>>k;
    vll costo(2001,-1);
    costo[0] = 0;
    F1(i,2000) {
        costo[i] = costo[i-1]*2 + 2;
        if(costo[i] > k) break;
    }
    if(k % 2 == 1){
        cout<<"-1\n";
        return;
    }
    vi res;
    while(k > 0){
        int i = 2000;
        while(costo[i] == -1 or costo[i] > k) i--;
        k -= costo[i];
        res.pb(i);
    }
    int n = 0;
    for(auto m : res) n += m;
    cout<<n<<'\n';
    for(auto m : res){
        cout<<"1 ";
        m--;
        while(m--) cout<<"0 ";
    }
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) d();
    return 0;
}