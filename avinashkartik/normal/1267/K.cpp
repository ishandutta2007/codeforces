
#include<bits/stdc++.h>
using namespace std;

#define fastio          ios::sync_with_stdio(0);    cin.tie(0); cout.tie(0);  cout<<fixed;  cout<<setprecision(24);
#define randomINT       mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define newl            cout<<"\n"
#define DISP(as)        for(auto it : as) cout<<it<<" ";newl;
#define all(x)          (x).begin(),(x).end()
#define mset(x,val)     memset(x,val,sizeof(x))
#define newl            cout<<"\n"
#define pb              push_back
#define mp              make_pair
#define f               first
#define s               second
#define dline          cerr<<"///REACHED///\n";
#define deb1(x)        cerr<<#x<<" = "<<x<<'\n';
#define deb2(x,y)      cerr<<'['<<#x<<','<<#y<<"] = "<<'['<<x<<','<<y<<']'<<'\n';
#define deb3(x,y,z)    cerr<<'['<<#x<<','<<#y<<','<<#z<<"] = "<<'['<<x<<','<<y<<','<<z<<']'<<'\n';

typedef long long               ll;
typedef long double             ld;
typedef vector<ll>              vll;
typedef pair<ll , ll>           pll;
typedef pair<ld, ld>            pld;
typedef unordered_map<ll, ll>   um;
typedef vector<pll>             vpll;

const ll    MAX5    =   1e+5 + 7;
const ll    MAX7    =   1e+7 + 7;
const ll    MAXN    =   MAX7;
const ll    INF     =   0x7f7f7f7f7f7f7f7f;
const int   INFi    =   0x7f7f7f7f;
const ll    MOD     =   1e+9 + 7;


// <------------- Declare Variables Here ------------> //

ll T = 1;

ll n, m, x, k;
ll s, t;
vll a, b;

// <------------- Implement Functions Here ----------> //

ll NCR(ll n, ll r) {
    if (r == 0) return 1;
    if (n < r) return 0; 
    if (r > n / 2) return NCR(n, n - r);
    ll res = 1;
    for (ll k = 1; k <= r; ++k) {
        res *= n - k + 1;
        res /= k;
    }
    return res;
}

// <------------- Start of main() -------------------> //

void MAIN() {
    cin>>n;
    ll prod  = 1, prod1 = 1;
    ll sub = 1;

    map<ll,ll> val;
    set<ll,greater<ll>> ans;
    vll v;

    ll i=2;
    ll cou = 0;
    while(n) {
        ans.insert(n%i);
        val[n%i]++;
        n/=i;
        i++;
        cou++;
    }

    for(auto it : ans) v.pb(it);
    ll sum = 0;
    //DISP(v);
    for(ll i=0;i<v.size()-1;i++) {  
        prod *= NCR(cou + 1 - v[i] - sum ,val[v[i]]);
        prod1 *= NCR(cou  - v[i] - sum ,val[v[i]]);
        sum += val[v[i]];
    }
    //cout<<prod1<<" ";newl;
    if(v[v.size()-1]!=0) prod1 = 0;
    
    cout<<prod - 1 - prod1;newl;
}

int main() {
    cin >> T;
    while (T--) {
        MAIN();
    }
    return 0;
}