#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

#define all(v) (v).begin(),(v).end()

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    int min_ans = n + 1;
    // even
    int cnt0, cnt1;
    {
        cnt0 = cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                if (a[i] == '1')
                    cnt1++;
                else 
                    cnt0++;
            }
        }
        if (cnt0 == cnt1)
            min_ans = min(min_ans, cnt0 + cnt1);
    }
    // odd
    {
        cnt0 = cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                if (a[i] == '1')
                    cnt1++;
                else
                    cnt0++;
            }
        }
        if (cnt1 - 1 == cnt0) {
            min_ans = min(min_ans, cnt0 + cnt1);
        }
    }
    

    if (min_ans == n + 1) {
        min_ans = -1;
    }
    cout << min_ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}