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
#define eb emplace_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound((v).begin(), (v).end(), x) - (v).begin())
#define ubv(v, x) (upper_bound((v).begin(), (v).end(), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 64 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int MN = 1 << 18;
int k, n;
string str;
int arr[MN];
pll sorted[MN];

int main(){
    cin >> k >> str;
    n = 1 << k;

    for (int i = 0; i < n; i++) {
        arr[i] = str[i] - 'a';
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            sorted[j] = {(ll) arr[j]*n + arr[j ^ (1<<i)], j};
        }
        sort(sorted, sorted + n);

        int cur = arr[sorted[0].sn] = 0;
        for (int j = 1; j < n; j++) {
            arr[sorted[j].sn] = cur += sorted[j].fs != sorted[j-1].fs;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << str[i ^ sorted[0].sn];
    }
    cout << '\n';
}