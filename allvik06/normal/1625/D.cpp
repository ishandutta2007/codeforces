#include <iostream>
#include <vector>
#include <map>

using namespace std;
int k;
vector <int> ans;

bool calc(vector <int>& a, vector <int>& b, int num = 29, bool f = false) {
    if (a.empty() || (f && b.empty())) return false;
    if (num == -1) {
        ans.push_back(a[0]);
        ans.push_back(b[0]);
        return true;
    }
    if (f) {
        vector <int> a0, a1, b0, b1;
        for (int i : a) {
            if ((i >> num) & 1) a1.push_back(i);
            else a0.push_back(i);
        }
        for (int i : b) {
            if ((i >> num) & 1) b1.push_back(i);
            else b0.push_back(i);
        }
        if ((k >> num) & 1) {
            if (calc(a0, b1, num - 1, true)) return true;
            if (calc(a1, b0, num - 1, true)) return true;
            return false;
        } else {
            if (!a0.empty() && !b1.empty()) {
                ans.push_back(a0.back());
                ans.push_back(b1.back());
                return true;
            }
            if (!a1.empty() && !b0.empty()) {
                ans.push_back(a1.back());
                ans.push_back(b0.back());
                return true;
            }
            if (calc(a0, b0, num - 1, true)) return true;
            if (calc(a1, b1, num - 1, true)) return true;
            return false;
        }
    } else {
        vector <int> a0, a1;
        for (int i : a) {
            if ((i >> num) & 1) a1.push_back(i);
            else a0.push_back(i);
        }
        if ((k >> num) & 1) {
            if (!calc(a0, a1, num - 1, true)) {
                ans.push_back(a.front());
            }
        } else {
            calc(a0, b, num - 1);
            calc(a1, b, num - 1);
        }
    }
    return false;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    map <int, int> d;
    for (int i = 0; i < n; ++i) d[a[i]] = i;
    if (k == 0) {
        cout << n << "\n";
        for (int i = 1; i <= n; ++i) cout << i << " ";
        return 0;
    }
    vector <int> b;
    calc(a, b);
    if ((int)ans.size() < 2) cout << -1;
    else {
        cout << (int)ans.size() << "\n";
        for (int i : ans) cout << d[i] + 1 << " ";
    }
}