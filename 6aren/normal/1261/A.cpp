#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

void swap(string &s, int l, int r) {
    for (int i = l; i <= r; i++) {
        int v = (r + l - i);
        if (v <= i) break;
        char temp = s[i];
        s[i] = s[v];
        s[v] = temp;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int test;
    cin >> test;
    while (test--) {
        vector<ii> res;
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string t;
        for (int i = 1; i < k; i++) {
            t += "()";
        }
        string temp;
        for (int i = 1; i <= (n / 2 - k + 1); i++) {
            temp += "(";
        }
        for (int i = 1; i <= (n / 2 - k + 1); i++) {
            temp += ")";
        }
        t += temp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                int u;
                for (int j = i + 1; j < n; j++) {
                    if (s[j] == t[i]) {
                        u = j;
                        break;
                    }
                }
                res.pb({i, u});
                swap(s, i, u);
            }
        }
        cout << res.size() << '\n';
        for (auto u : res) cout << u.x + 1 << ' ' << u.y + 1 << '\n';
    }
    return 0;
}