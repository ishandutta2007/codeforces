#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x - 1].push_back(y - 1);
        a[y - 1].push_back(x - 1);
    }
    vector <int> d(n);
    vector <bool> used(n);
    set <pair <int, int>> s;
    for (int i = 0; i < n; ++i) {
        s.insert({0, i});
    }
    int ans = -1, lol = 0;
    while (!s.empty()) {
        pair <int, int> cur = *s.begin();
        s.erase(s.begin());
        if (cur.first == lol) ++ans;
        used[cur.second] = true;
        ++lol;
        for (int i : a[cur.second]) {
            if (!used[i]) {
                s.erase({d[i], i});
                d[i]++;
                s.insert({d[i], i});
            }
        }
    }
    cout << ans;
	return 0;
}