#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        map<char, int> cnt;
        for (auto &c : s) cnt[c]++;
        int mx = max({cnt['R'], cnt['S'], cnt['P']});
        if (cnt['R'] == mx) cout << string(n, 'P') << "\n";
        else if (cnt['S'] == mx) cout << string(n, 'R') << "\n";
        else cout << string(n, 'S') << "\n";
    }

    return 0;
}