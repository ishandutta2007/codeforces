#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
// using ld = long double; 
using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;

    int tests = 1;
    cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

void solve() {      
    string s;
    cin >> s;  
    int n = sz(s);

    vector<int> cnt(26);
    for (char c : s) {
        ++cnt[c - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] == 1) {
            string t;
            t += char(i + 'a');
            for (int j = 0; j < 26; ++j) {
                if (j != i) {
                    for (; cnt[j]; --cnt[j]) {
                        t += char(j + 'a');
                    }
                }
            }
            cout << t << '\n';
            return;
        } else if (cnt[i] == n) {
            cout << s << '\n';
            return;
        }
    }

    int k = -1;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i]) {
            k = i;
            break;
        }
    }
    string r;
    for (int i = 25; i > k; --i) {
        for (; cnt[i]; --cnt[i]) {
            r += char(i + 'a');
        }
    }

    string t;
    t += char(k + 'a');
    --cnt[k];

    if (cnt[k] <= sz(r) + 1) {  
        t += char(k + 'a');
        --cnt[k];
        for (; cnt[k] > 0; --cnt[k]) {
            t += r.back();
            r.pop_back();
            t += char(k + 'a');
        }
        reverse(all(r));
        t += r;
        cout << t << "\n";
        return;
    }

    if (r[0] == r.back()) {
        t += r;
        for (; cnt[k]; --cnt[k]) {
            t += char(k + 'a');
        }
        cout << t << "\n";
        return;
    }

    t += r.back();
    r.pop_back();
    for (; cnt[k]; --cnt[k]) {
        t += char(k + 'a');
    }

    for (int i = sz(r) - 1; i >= 0; --i) {
        if (r[i] != t[1]) {
            t += r[i];
            r.erase(r.begin() + i);
            break;
        }
    }
    reverse(all(r));
    t += r;
    cout << t << "\n";
}