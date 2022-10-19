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
#define dbgArr(arr, n) {cerr << #arr; FR(_i, n) cerr << ' ' << (arr)[_i]; cerr << endl;}

const int MN = 2e5 + 5;
int t, n;
int arr[MN];
vi adjList[MN];

pll dfs(int n1, int k){
    int nc = SZ(adjList[n1]);
    ll res = (ll) arr[n1] * k;
    if(!nc) return {res, res + arr[n1]};

    int nxtK = k/nc;
    vector<ll> vec;
    for(int n2 : adjList[n1]){
        auto [v1, v2] = dfs(n2, nxtK);
        res += v1;
        vec.pb(v2 - v1);
    }

    sort(ALL(vec));
    reverse(ALL(vec));

    FR(i, k % nc) res += vec[i];

    return {res, res + arr[n1] + vec[k % nc]};
}

int main(){
    boost();
    cin >> t;

    while(t--){
        int k;
        cin >> n >> k;
        FR(i, n-1){
            int p; cin >> p; p--;
            adjList[p].pb(i+1);
        }
        FR(i, n) cin >> arr[i];

        cout << dfs(0, k).fs << '\n';

        FR(i, n) adjList[i].clear();
    }
}