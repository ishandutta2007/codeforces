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
#define ms(a, x) memset(a, x, sizeof(a))
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int MN = 2030;
int t, n;
int arr[MN];

// Return false if impossible
bool solve(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i]--;
    }

    vi ans;
    for (int i = n-1; i > 0; i -= 2) {
        for (int j = 0; j < n; ++j) {
            if(arr[j] == i){
                if(j % 2 == 1) return false;
                ans.pb(j+1);
                reverse(arr, arr + j+1);
            }
        }
        for (int j = 0; j < n; ++j) {
            if(arr[j] == i-1){
                if(j % 2 == 0) return false;
                ans.pb(j);
                reverse(arr, arr + j);
                ans.pb(j+2);
                reverse(arr, arr + j+2);
            }
        }
        ans.pb(3);
        reverse(arr, arr + 3);
        ans.pb(i+1);
        reverse(arr, arr+i+1);
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " \n"[i == ans.size()-1];
    }

    for (int i = 0; i < n; ++i) {
        assert(arr[i] == i);
    }
    return true;
}

int main(){
    boost();
    cin >> t;
    while(t--){
        if(!solve()) cout << "-1\n";
    }
}