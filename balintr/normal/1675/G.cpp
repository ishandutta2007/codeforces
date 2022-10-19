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

const int MN = 256;
int n, m;
int arr[MN];
int oldDp[MN][MN*2], newDp[MN][MN*2]; // [cap][movL]

int main(){
    boost();
    cin >> n >> m;
    FR(i, n) cin >> arr[i];

    ms(newDp, INF);
    FR(i, MN) newDp[i][MN] = 0;

    FORR(i, n-1, 0){
        memcpy(oldDp, newDp, sizeof(oldDp));
        ms(newDp, INF);

        FOR(j, 1, MN) FOR(k, 1, MN*2) oldDp[j][k] = min(oldDp[j][k], oldDp[j-1][k-1]);

        FR(j, MN) FR(k, MN*2){
            int nv = arr[i] - (k-MN);
            if(j-nv+MN >= 0 && j-nv+MN < 2*MN) newDp[j][k] = oldDp[j][j-nv+MN] + abs(k-MN);
        }
    }

    int ans = INF;
    FR(i, MN) ans = min(ans, newDp[i][MN]);

    cout << newDp[MN-1][MN] << '\n';
}