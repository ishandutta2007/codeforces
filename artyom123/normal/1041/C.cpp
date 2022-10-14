#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    multiset <pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert({x, i});
    }
    vector <int> ans(n);
    int answer = 0;
    while (!s.empty()) {
        int now = s.begin()->first;
        ans[s.begin()->second] = answer + 1;
        s.erase(s.begin());
        while (s.lower_bound({now + d + 1, 0}) != s.end()) {
            auto it = s.lower_bound({now + d + 1, 0});
            now = it->first;
            ans[it->second] = answer + 1;
            s.erase(it);
        }
        answer++;
    }
    cout << answer << "\n";
    for (auto c : ans) {
        cout << c << " ";
    }
    return 0;
}