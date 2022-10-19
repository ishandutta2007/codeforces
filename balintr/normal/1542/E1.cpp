#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, bool> pib;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pib> vpib;
typedef int8_t int8;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int MN = 55;
int n;
ll mod;

ll invs[MN][MN*MN]; // [i][j] is # of permutations of length i with exactly j inversions
ll suff[MN][MN*MN]; // [i][j] is sum of invs[i][j+1..]
ll col[MN][MN];

int main(){
    boost();
    cin >> n >> mod;

    // PreCalc invs
    invs[0][0] = 1;
    for (int i = 1; i < MN; ++i) {
        ll sum = 0;
        for (int j = 0; j <= i*(i-1)/2; ++j) {
            int low = j-i;
            if(low >= 0) sum += mod - invs[i-1][low];
            sum += invs[i-1][j];
            sum %= mod;
            invs[i][j] = sum;
        }
    }

    for (int i = 0; i < MN; ++i) {
        ll sum = 0;
        for (int j = MN*MN-1; j >= 0; --j) {
            sum += invs[i][j];
            sum %= mod;
            suff[i][j] = sum;
        }
    }

    for (int i = 0; i < MN; ++i) {
        for (int j = 0; j < MN; ++j) {
            ll sum = 0;
            for (int k = 0; k < MN*MN; ++k) {
                if(k + j >= MN*MN) break;
                sum += invs[i][k] * suff[i][k+j];
                sum %= mod;
            }
            col[i][j] = sum;
        }
    }

    ll total = 0;
    ll cur = 1;
    // i = ind to switch
    for (int i = 0; i < n; ++i) {
        if(i != 0) cur *= n-i+1;
        cur %= mod;
        // j = original val
        for (int j = 0; j < n-i; ++j) {
            // k = new val
            for (int k = j+1; k < n-i; ++k) {
                total += cur * col[n-i-1][k-j+1];
                total %= mod;
            }
        }
    }

    cout << total << '\n';
}