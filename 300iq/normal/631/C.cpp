#include <bits/stdc++.h>
#define mp make_pair

using namespace std;


int main() {
    int n, m, r, t, last;
    cin >> n >> m;
    multiset <int> s;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    deque <pair <int, int> > q;
    for (int i = 0; i < m; i++) {
        cin >> t >> r;
        while (!q.empty() && q.back().first < r) {
            q.pop_back();
        }
        q.push_back(make_pair(r, t));
    }
    int v = q.front().first;
    for (int i = 0; i < v; i++) {
        s.insert(a[i]);
    }
    m = q.size();
    vector <int> ans(v);
    for (int i = 0; i < m; i++) {
        pair <int, int> qe = q.front();
        q.pop_front();
        r = qe.first;
        t = qe.second;
        if (i == m - 1) {
            last = 0;
        } else {
            last = q.front().first;
        }
        if (t == 1) {
            for (int j = r - 1; j >= last; j--) {
                ans[j] = *s.rbegin();
                s.erase(--s.end());
            }
        } else {
            for (int j = r - 1; j >= last; j--) {
                ans[j] = *s.begin();
                s.erase(s.begin());
            }
        }
    }
    int uk = ans.size();
    while (uk < n) {
        ans.push_back(a[uk++]);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}