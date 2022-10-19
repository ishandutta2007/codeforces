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
int freq[26];
int psa[27];

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n;
        string str;
        cin >> str;

        ms(freq, 0);
        ms(psa, 0);

        for (int i = 0; i < n; ++i) {
            freq[str[i]-'a']++;
        }
        for (int i = 1; i <= 26; ++i) {
            psa[i] = psa[i-1] + freq[i-1];
        }

        int total = 0;
        for (int i = 0; i < n; ++i) {
            int expected = upper_bound(psa, psa + 27, i) - psa;
            if(expected-1 != str[i]-'a') total++;
        }
        cout << total << '\n';
    }
}