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

int t, n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        string str;
        for (int i = 0; i < n/2*2; ++i) {
            str.pb('a');
        }
        if(n & 1) str.pb('c');
        str[n/2] = 'b';
        cout << str << '\n';
    }
}

/*
const int n = 15;
unordered_map<int, int> freq[n];

int main(){
    boost();
    for (int s = 0; s < (1 << n); ++s) {
        for (int i = 0; i < n; ++i) {
            freq[i].clear();
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= n-i; ++j) {
                freq[j-1][(s >> i) & ((1 << j) - 1)]++;
            }
        }
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            for(auto [a, x] : freq[i]){
                if(!(x & 1)) valid = false;
            }
        }
        if(valid){
            for (int i = 0; i < n; ++i) {
                cout << (((s >> i) & 1) ? 'b' : 'a');
            }
            cout << '\n';
        }
    }
}
 */