#include <bits/stdc++.h>
using namespace std;

typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0)
#define ms(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound((v).begin(), (v).end(), x) - (v).begin())
#define ubv(v, x) (upper_bound((v).begin(), (v).end(), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define dbg(x) {cerr << #x << ' ' << x << endl;}
#define dbgArr(arr, n) {cerr << #arr; FR(_i, n) cerr << ' ' << arr[_i]; cerr << endl;}

bool isPalin(int x){
    string str = to_string(x);
    int n = SZ(str);
    FR(i, n) if(str[i] != str[n-i-1]) return false;
    return true;
}

const int MOD = 1e9 + 7;
const int MN = 4e4 + 5;
int dp[MN];

int main(){
    boost();
    dp[0] = 1;
    FOR(i, 1, MN){
        if(!isPalin(i)) continue;
        FOR(j, i, MN){
            dp[j] += dp[j-i];
            if(dp[j] >= MOD) dp[j] -= MOD;
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
}