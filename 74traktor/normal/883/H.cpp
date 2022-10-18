#include<bits/stdc++.h>

using namespace std;

map < char, int > cnt;
map < char, int > cpy;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ww = 1;
    cin >> n;
    string s;
    cin >> s;
    for (auto c : s) cnt[c]++;
    cpy = cnt;
    for (int k = n; k >= 1; --k) {
        if (n % k != 0) continue;
        if (k % 2 == 1 && (n - n / k) % 2 != 0) continue;
        cnt = cpy;
        if (k % 2 == 0) {
            if (!ww) continue;
        ww = 0;
            int flag = 1;
            for (auto c : cnt) {
                if (c.second % 2 == 1) flag = 0;
            }
            if (!flag) continue;
            cout << n / k << '\n';
            for (int j = 1; j <= n / k; ++j) {
                string pref = "";
                vector < pair < char, int > > del;
                for (auto c : cnt) {
                    int add = min(c.second, k - 2 * (int)pref.size());
                    for (int i = 1; i <= add / 2; ++i) pref += c.first;
                    del.push_back({c.first, add});
                }
                for (auto key : del) cnt[key.first] -= key.second;
                string cur = pref;
                reverse(pref.begin(), pref.end());
                cur += pref;
                cout << cur << " ";
            }
            exit(0);
        } else {
            int flag = 1;
            vector < char > good;
            for (auto c : cnt) {
                if (c.second % 2 == 1) good.push_back(c.first);
            }
            for (auto key : good) cnt[key]--;
            while ((int)good.size() < n / k) {
                for (auto c : cnt) {
                    if (c.second > 1) {
                        good.push_back(c.first);
                        good.push_back(c.first);
                        break;
                    }
                }
                cnt[good.back()] -= 2;
            }
            if ((int)good.size() != n / k) continue;
            cout << n / k << '\n';
            for (int j = 1; j <= n / k; ++j) {
                string pref = "";
                vector < pair < char, int > > del;
                for (auto c : cnt) {
                    int add = min(c.second, (k - 1) - 2 * (int)pref.size());
                    for (int i = 1; i <= add / 2; ++i) pref += c.first;
                    del.push_back({c.first, add});
                }
                for (auto key : del) cnt[key.first] -= key.second;
                string cur = pref;
                reverse(pref.begin(), pref.end());
                cur += good.back();
                cur += pref;
                good.pop_back();
                cout << cur << " ";
            }
            exit(0);
        }
    }
    return 0;
}