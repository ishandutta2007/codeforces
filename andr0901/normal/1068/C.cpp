#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> gr(n + 1);
    while (m --> 0) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        if (tmp1 > tmp2) swap(tmp1, tmp2);
        gr[tmp1].push_back(tmp2);
    }
    vector <vector <int>> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j : gr[i]) {
            ans[i].push_back(1000 * i + j);
            ans[j].push_back(1000 * i + j);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i].size() == 0) {
            cout << "1\n" << 10000000 + i << " " << 10000000 + i << "\n";
            continue;
        }
        cout << ans[i].size() << "\n";
        for (int j : ans[i]) {
            cout << i << " " << j << "\n";
        }
    }
    return 0;
}