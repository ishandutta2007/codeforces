#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> chords(k);
        vector<int> check(2 * n, false);
        for (auto &e : chords) {
            cin >> e.first >> e.second;
            e.first--;
            e.second--;
            check[e.first] = check[e.second] = true;
        }
        vector<int> rem;
        for (int i = 0; i < 2 * n; i++)
            if (!check[i]) rem.push_back(i);
        for (int i = 0; i < rem.size() / 2; i++) {
            chords.emplace_back(rem[i], rem[i + rem.size() / 2]);
        }
        for (auto &e : chords) {
            if (e.first > e.second) swap(e.first, e.second);
        }
        sort(chords.begin(), chords.end());
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (chords[i].first < chords[j].first &&
                    chords[j].first < chords[i].second &&
                    chords[i].second < chords[j].second) {
                    res++;
                }
            }
        }
        cout << res << '\n';
    }

    return 0;
}