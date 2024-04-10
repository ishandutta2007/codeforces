#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>
#include <random>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)
            (res *= a) %= MOD;
        p >>= 1;
        (a *= a) %= MOD;
    }
    return res;
}

mt19937 rng(123);

void solve() {
    int n;
    ll l;
    cin >> n >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<string> words(n);
    int v = 1;
    vector<string> pref{""};
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        v += words[i].length();
        string s;
        for (int j = 0; j < words[i].length(); j++) {
            s += words[i][j];
            pref.push_back(s);
        }
    }
    unordered_map<string, int> cost;
    for (int i = 0; i < n; i++) {
        string s = words[i];
        reverse(s.begin(), s.end());
        cost[s] += a[i];
    }
    vector<ll> A(v * v, -20001LL), B(v * v), C(v * v);
    for (int i = 0; i < v; i++) {
        for (int j = 1; j < v; j++) {
            if (pref[i].length() + 1 < pref[j].length())
                continue;
            int suf = pref[j].length() - 1;
            if (pref[i].substr(pref[i].length() - suf, suf) != pref[j].substr(0, suf))
                continue;
            string cur;
            cur += pref[j].back();
            int w = cost[cur];
            for (int j = 1; j <= suf; j++) {
                cur += pref[i][pref[i].length() - j];
                w += cost[cur];
            }
            A[i * v + j] = w;
        }
    }
    auto mul=[&](vector<ll> &a, vector<ll> &b) {
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++) {
                C[i * v + j] = -1;
                for (int k = 0; k < v; k++) {
                    C[i * v + j] = max(C[i * v + j], a[i * v + k] + b[k * v + j]);
                }
                if (C[i * v + j] < 0)
                    C[i * v + j] = -20001;
            }
    };
    while (l) {
        if (l & 1) {
            mul(A, B);
            B = C;
        }
        l >>= 1;
        mul(A, A);
        A = C;
    }
    cout << *max_element(B.begin(), B.begin() + v) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}