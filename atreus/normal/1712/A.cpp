#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int c[maxn], p[maxn];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        c[i] = p[i];
    }
    sort(c + 1, c + n + 1);
    map<int,int> mp;
    for (int i = 1; i <= k; i++)
        mp[c[i]]++;
    int answer = k;
    for (int i = 1; i <= k; i++) {
        if (mp[p[i]] != 0) {
            answer--;
            mp[p[i]]--;
        }
    }
    cout << answer << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}