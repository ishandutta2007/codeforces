#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef int8_t int8;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define ms(a, x) memset(a, x, sizeof(a))
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

int queryOr(int a, int b){
    cout << "or " << a+1 << ' ' << b+1 << endl;
    int res;
    cin >> res;
    return res;
}

int queryAnd(int a, int b){
    cout << "and " << a+1 << ' ' << b+1 << endl;
    int res;
    cin >> res;
    return res;
}

const int MN = 1e4 + 5;
int n, k;

int vals[3][31];
int arr[MN];

int main(){
    cin >> n >> k;

    ms(vals, -1);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < i; ++j) {
            int o = queryOr(i, j);
            for (int l = 0; l < 31; ++l) {
                if(((o >> l) & 1) == 0) vals[i][l] = vals[j][l] = 0;
            }
            int a = queryAnd(i, j);
            for (int l = 0; l < 31; ++l) {
                if(((a >> l) & 1) == 1) vals[i][l] = vals[j][l] = 1;
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 30; j >= 0; --j) {
            if(vals[i][j] == -1) vals[i][j] = !vals[(i+1)%3][j];
            arr[i] = (arr[i] << 1) | vals[i][j];
        }
    }

    for (int i = 3; i < n; ++i) {
        arr[i] = queryAnd(i-1, i) + queryOr(i-1, i) - arr[i-1];
    }

    sort(arr, arr + n);
    cout << "finish " << arr[k-1] << endl;
}