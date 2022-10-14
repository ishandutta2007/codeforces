#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

mt19937 gen(time(0));

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
    sort(a.begin(), a.end());
    vector <int> b;
    vector <int> c;
    for (auto &l : a) {
        if (l <= 0) {
            b.pb(l);
        }
        if (l >= 0) {
            c.pb(l);
        }
    }
    long long ans = 0;
    int l = b.size();
    for (int r = (int)b.size() - 1; r >= 0; r--) {
        if (l > r) {
            l = r;
        }
        while (l - 1 >= 0 && 2 * b[r] <= b[l - 1]) {
            l--;
        }
        ans += (r - l);
    }
    int r = -1;
    for (int l = 0; l < c.size(); l++) {
        if (r < l) {
            r = l;
        }
        while (r + 1 < c.size() && c[l] * 2 >= c[r + 1]) {
            r++;
        }
        ans += (r - l);
    }
    if (c.size() > 0 && c[0] == 0) {
        c.erase(c.begin());
    }
    if (c.size() == 0 || b.size() == 0) {
        cout << ans;
        return 0;
    }
    for (int i = 0; i < b.size(); i++) {
        int left = -1, right = c.size();
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (c[mid] <= -2 * b[i]) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        int second = left;
        left = -1;
        right = c.size();
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (c[mid] * 2 >= -b[i]) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        int first = right;
        if (first == c.size() || second == -1) {
            continue;
        }
        ans += max(0, second - first + 1);
    }
    cout << ans;
    return 0;
}