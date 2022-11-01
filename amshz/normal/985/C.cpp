#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;
#define ts(x)                       to_string(x)
#define ti(x)                       stoi(x)
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define mine(v)                     *min_element(all(v))
#define maxe(v)                     *max_element(all(v))
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define SIZE(x)                     (int)x.size()
#define endl                        "\n"
inline ll input(){ll n; cin >> n ; return n;}

//void add(int I, int value){seg[I += MAXN] = value;for (I >>= 1; I; I >>= 1){seg[I] = __gcd(seg[I << 1], seg[I << 1 | 1]);}}

//int query(int l, int r){int ans = seg[l + MAXN];for (l += MAXN, r += MAXN + 1; l < r; l >>= 1, r >>= 1){if(l & 1) ans = __gcd(ans, seg[l ++]);if(r & 1) ans = __gcd(ans, seg[-- r]);}return ans;}

string base2(ll n){string a = "";while(n >= 2){a += (char)(n % 2 + '0');n /= 2;}a += (char)(n + '0');reverse(all(a));return a;}

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const ll INF = 8e18;

ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? (a * pw(a * a % MOD, b / 2)) % MOD : pw(a * a % MOD, b / 2))); }

int v[MAXN], cnt[MAXN];

int main(){
    fast_io;
    //cout << fixed << setprecision(15);
    //scanf("%d %d %f %lld %s %c", &x);
    //printf("%d %d %f %lld %s %c", x);
    int n, k, l;
    cin >> n >> k >> l;
    for(int i = 0; i < n; i++){
        cnt[i] = k;
    }
    for(int i = 0; i < (n * k); i++){
        cin >> v[i];
    }
    sort(v, v + (n * k));
    ll ans = 0;
    if(v[n - 1] > v[0] + l){
        return cout << 0, 0;
    }
    int ind = 0;
    for(int j = 0; j < n * k; j++){
        if(v[j] <= v[0] + l){
            ind = j;
        }
    }
    int t = ind + 1, t2 = n;
    for(int i = ind; i >= 0; i--){
        //cout << i << " " << t << " " << t2 << endl;
        if((t - 1) <= (t2 - 1) * k){
            //cout << "bardashtam  i: " << i << " " << v[i] << endl;
            ans += v[i];
            t2--;
        }
        t--;
    }
    cout << ans;
    return 0;
}