#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int INF = 1e9 + 1;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (auto &c : a) {
        cin >> c;
    }
    vector <int> u(1e5 + 1);
    multiset <int> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s.find(u[a[i]]) != s.end()) {
            s.erase(s.find(u[a[i]]));
        }
        s.insert(u[a[i]] + 1);
        u[a[i]]++;
        int first = *s.begin();
        int last = *s.rbegin();
        s.erase(s.find(*s.rbegin()));
        int pr_last = -1;
        if (s.size() == 0) {
            pr_last = first;
        }
        else {
            pr_last = *s.rbegin();
        }
        if ((last - first == 1 && pr_last == first) || s.size() == 0) {
            ans = i + 1;
            s.insert(last);
            continue;
        }
        s.insert(last);
        if (first == 1) {
            s.erase(s.begin());
            int pr_first = *s.begin();
            if (pr_first == last) {
                ans = i + 1;
            }
            s.insert(first);
        }
    }
    cout << ans;
    return 0;
}