#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<pair<int, int>> cnt(n);
        for (int i = 0; i < n; i++) {
            int x, p;
            cin >> x >> p;
            cnt[x - 1].first++;
            cnt[x - 1].second += p;
        }
        sort(cnt.begin(), cnt.end());
        vector<int> added(n);
        int total = 0;
        int good = 0;
        int last = 1e9;
        multiset<int> cur;
        int firstna = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            int to_do = max(0, min(last, cnt[i].first));
            while (firstna >= 0 && cnt[firstna].first >= to_do) {
                cur.insert(cnt[firstna].second);
                firstna--;
            }
            total += to_do;
            auto it = cur.end();
            it--;
            good += min(*it, to_do);
            cur.erase(it);
            last = to_do - 1;
        }
        cout << total << " " << good << endl;
    }
}