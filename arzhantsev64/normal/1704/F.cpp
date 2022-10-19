#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pt pair<int, int>
#define x first
#define y second

const int mod = 998244353;

vector<int> nimb(1000);

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int R = 0;
    int B = 0;
    for (char c : s){
        if (c == 'B')
            B++;
        if (c == 'R')
            R++;
    }
    if (B > R) {
        cout << "Bob" << '\n';
        return;
    }
    if (R > B) {
        cout << "Alice" << '\n';
        return;
    }

    vector<int> lens;
    char last = 'q';
    int cur = 0;
    for (char c : s) {
        if (c != last) {
            cur++;
        } else {
            lens.push_back(cur);
            cur = 1;
        }
        last = c;
    }
    lens.push_back(cur);

    int res = 0;
    for (int i : lens){
        if (i < 1000)
            res ^= nimb[i];
        else {
            res ^= nimb[i % 34 + 340];
        }
    }
    if (res == 0)
        cout << "Bob\n";
    else
        cout << "Alice\n";

    // cout << B << ' ' << R << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    nimb[0] = 0;
    nimb[1] = 0;
    for (int i = 2; i < 1000; ++i) {
        unordered_set<int> ns;
        for (int j = 0; j < i - 1; ++j)
            ns.insert(nimb[j] ^ nimb[i - j - 2]);
        int t = 0;
        while (ns.count(t))
            t++;
        nimb[i] = t;
    }

    int t;
    cin >> t;
    while (t--)
         solve();

    return 0;
}

/*

7 4 8 1 6 10 3 5 2 9
*/