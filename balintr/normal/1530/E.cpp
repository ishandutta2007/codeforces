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

const int MN = 1e5 + 5;
int t, n;
string str;
char sorted[MN];
int freq[26];

void solve(){
    memset(freq, 0, sizeof(freq));
    cin >> str;
    n = str.length();
    for (int i = 0; i < n; ++i) {
        sorted[i] = str[i];
        freq[str[i] - 'a']++;
    }
    sort(sorted, sorted + n);

    int numUnique = 0;

    for (int c = 0; c < 26; ++c) {
        if(freq[c]) numUnique++;
        if(freq[c] == 1){
            char ch = c + 'a';
            cout << ch;
            for (int i = 0; i < n; ++i) {
                if(sorted[i] != ch) cout << sorted[i];
            }
            cout << '\n';
            return;
        }
    }

    int c = sorted[0] - 'a';
    char ch1 = sorted[0];

    if(numUnique == 1){
        cout << str << '\n';
        return;
    }

    if(freq[c] <= n/2 + 1){
        int j = freq[c];
        int f = freq[c]-2;
        cout << ch1 << ch1;
        while(f--){
            cout << sorted[j++] << ch1;
        }
        for(; j < n; ++j){
            cout << sorted[j];
        }
        cout << '\n';
    }
    else {
        if(numUnique == 2){
            char ch2 = sorted[freq[c]];
            cout << ch1;
            for (int i = 0; i < freq[ch2 - 'a']; ++i) {
                cout << ch2;
            }
            for (int i = 0; i < freq[c]-1; ++i) {
                cout << ch1;
            }
            cout << '\n';
            return;
        }

        char ch2 = sorted[freq[c]];
        char ch3 = sorted[freq[c] + freq[ch2 - 'a']];
        freq[ch2-'a']--;
        freq[ch3-'a']--;

        cout << ch1 << ch2;
        for (int i = 0; i < freq[c]-1; ++i) {
            cout << ch1;
        }
        cout << ch3;

        for (int i = ch2-'a'; i < 26; ++i) {
            for (int j = 0; j < freq[i]; ++j) {
                cout << (char) (i+'a');
            }
        }

        cout << '\n';
    }
}

int main(){
    boost();
    cin >> t;
    while(t--){
        solve();
    }
}