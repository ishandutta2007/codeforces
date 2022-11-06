#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

bool isVowel(const char c) {
    return set<char>{'a', 'e', 'i', 'o', 'u'}.count(c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<string> a(n);
    vector<bool> taken(n, false);
    for (string &s : a)
        cin >> s;

    vector<pair<int, int>> pairs[2];

    for (int rep = 0; rep < 2; ++rep) {
        auto f = [&](const int i) {
            const int c = count_if(a[i].begin(), a[i].end(), isVowel);
            if (rep == 1)
                return c;
            int j = (int) a[i].size() - 1;
            while (!isVowel(a[i][j])) --j;
            return c * 200 + (int) a[i][j];
        };
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i)
            if (!taken[i])
                mp[f(i)].push_back(i);
        for (auto &&e : mp)
            for (int i = 0; i + 1 < (int) e.second.size(); i += 2) {
                const int i1 = e.second[i];
                const int i2 = e.second[i + 1];
                pairs[rep].push_back({i1, i2});
                taken[i1] = taken[i2] = true;
            }
    }

    const int ans = min(pairs[0].size(), (pairs[0].size() + pairs[1].size()) >> 1);
    if (pairs[0].size() > ans)
        pairs[1].insert(pairs[1].end(), pairs[0].begin() + ans, pairs[0].end());
    cout << ans << endl;
    for (int i = 0; i < ans; ++i) {
        cout << a[pairs[1][i].first] << ' ' << a[pairs[0][i].first] << '\n';
        cout << a[pairs[1][i].second] << ' ' << a[pairs[0][i].second] << '\n';
    }
    return 0;
}