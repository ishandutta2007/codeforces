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

const int MN = 1e5 + 5;
int t, n;
int arr[MN], brr[MN], nxt[MN];
bool vis[MN];

void solve(){
    cin >> n;
    FR(i, n) cin >> arr[i], arr[i]--;
    FR(i, n) cin >> brr[i], brr[i]--;
    FR(i, n) nxt[arr[i]] = brr[i];

    int numOdd = 0;
    FR(i, n){
        if(vis[i]) continue;
        int len = 0;
        int n1 = i;
        do {
            vis[n1] = true;
            n1 = nxt[n1];
            len++;
        } while(n1 != i);
        numOdd += len & 1;
    }
    fill(vis, vis + n, 0);

    //dbg(numOdd);

    ll ans = 0;
    FR(i, n) ans += abs(i*2 - (n-1));
    assert(ans % 2 == 0);

    int sub = 0;
    FR(i, numOdd){
        sub += (i & 1);
        ans -= sub*2;
    }

    cout << ans << '\n';
}

int main(){
    boost();
    cin >> t;
    while(t--) solve();
}