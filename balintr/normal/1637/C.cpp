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

const int MN = 1e5 + 5;
int t, n;
int arr[MN];

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        bool bad = true;
        ll sum = 0;
        int numOdd = 0;
        int nnz = 0, num2p = 0;

        for (int i = 1; i < n-1; i++) {
            if(arr[i] >= 2){
                num2p++;
                if(!(arr[i] & 1)) bad = false;
            }
            sum += arr[i];
            numOdd += arr[i] & 1;
            nnz += bool(arr[i]);
        }

        if(num2p && nnz > 1) bad = false;

        if(bad){
            cout << "-1\n";
            continue;
        }
        cout << (sum+numOdd)/2 << '\n';
    }
}