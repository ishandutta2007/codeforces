// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()

using ll = long long;

template <typename T>
class DebugIntStream;

template <typename T>
DebugIntStream<T>& operator>>(DebugIntStream<T>&, T&);

template <typename T>
class DebugIntStream {
public:
    DebugIntStream(uint_fast64_t seed, T lowerBound, T upperBound) : 
        rng(seed), distrib(lowerBound, upperBound) {}

    friend DebugIntStream& operator>><T>(DebugIntStream&, T&);

private:
    mt19937_64 rng;
    uniform_int_distribution<T> distrib;
};

template<typename T>
DebugIntStream<T>& operator>>(DebugIntStream<T>& stream, T& num) {
    num = stream.distrib(stream.rng);
    return stream;
}

template <typename T, typename S = istream>
void read(vector<T>& vec, S& in = cin) {
    for (auto& elem : vec) {
        in >> elem;
    }
}

template <typename T, typename S = ostream>
void write(const vector<T>& vec, char delim = ' ', char last = '\n', S& out = cout) {
    bool first = true;
    for (auto& elem : vec) {
        if (!first) {
            out << delim;
        }
        out << elem;
        first = false;
    }
    out << last;
}

const int MOD = 1e9 + 7;
const int NUMB = 998'244'853;
const int DUMB = 998'244'353;

ll binpow(ll a, ll p, ll mod = MOD) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            res = res * a % mod;
        }
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(26);
    vector<pair<int, int>> last(26);
    for (int i = 0; i < 26; i++) {
        last[i] = {-1, char(i + 'a')};
    }
    int n = 0;
    for (int i = 0; i < s.length(); i++) {
        last[s[i] - 'a'].first = i;
        if (cnt[s[i] - 'a'] == 0) n++;
        cnt[s[i] - 'a']++;
    }
    sort(last.rbegin(), last.rend());
    vector<char> order;
    vector<int> len(26);
    for (int i = 0; i < 26; i++) {
        if (last[i].first != -1) {
            order.push_back(last[i].second);
            int id = last[i].second - 'a';
            len[id] = cnt[id] / (n - i);
        } else {
            break;
        }
    }
    string ans;
    for (char c : s) {
        if (!len[c - 'a']) {
            break;
        }
        ans += c;
        len[c - 'a']--;
    }
    reverse(order.begin(), order.end());
    vector<int> used(26);
    string t;
    for (int i = 0; i < n; i++) {
        for (char c : ans) {
            if (!used[c - 'a']) {
                t += c;
            }
        }
        used[order[i] - 'a'] = 1;
    }
    if (t == s) {
        cout << ans << ' ';
        for (char c : order) {
            cout << c;
        }
        cout << '\n';
    } else {
        cout << "-1\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}