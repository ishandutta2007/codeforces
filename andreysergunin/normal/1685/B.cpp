#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
 
void solve();
 
int task;
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s;
    cin >> s;
    int aa = 0, bb = 0;
    for (char c : s) {
        ++(c == 'A' ? aa : bb);
    }   
    // cout << s << endl;
    // cout << aa << " " << bb << endl;
    if (aa != a + c + d || bb != b + c + d) {
        cout << "NO\n";
        return;
    }

    int rem = 0;

    array<vector<int>, 2> arr;

    auto update = [&](int len, char last) {
        if (len == 0) {

        } else if (len & 1) {
            rem += (len - 1) / 2;
        } else {
            rem += (len - 1) / 2;
            arr[last == 'A' ? 1 : 0].push_back(len / 2);
        }
    };

    int len = 0;
    char last;
    for (char c : s) {
        if (len > 0 && last == c) {
            update(len, last);
            len = 0;
        }
        ++len;
        last = c;
    }
    update(len, last);

    for (int i = 0; i < 2; ++i) {
        sort(all(arr[i]));
        int x = i == 0 ? c : d;
        for (int l : arr[i]) {
            if (x >= l) {
                x -= l;
                ++rem;
            }
        }
    }

    // cout << rem << endl;
    // cout << c << " " << d << " " << c + d << " " << rem << endl;

    if (c + d > rem) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

}

// 2 3
// ABABAB BA ABAB