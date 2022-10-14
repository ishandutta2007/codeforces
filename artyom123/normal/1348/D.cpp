#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb emplace_back

void print(vector<int> &a) {
    cout << a.size() - 1 << "\n";
    for (int i = 1; i < a.size(); i++) {
        cout << a[i] - a[i - 1] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }
        vector<int> a;
        a.pb(1);
        int cur_sum = 1;
        while (cur_sum < n) {
            int d = n - cur_sum;
            if (d <= 2 * a.back()) {
                a.pb(d);
                cur_sum += d;
            } else {
                int x = min(a.back() * 2, (n - cur_sum) / 2);
                a.pb(x);
                cur_sum += x;
            }
        }
        print(a);
    }
    return 0;
}