#include <bits/stdc++.h>

#define int long long
using namespace std;

int q[1000000];
int st = 0;
int sz = 0;

main() {
    int n, k, uk1, uk2;
    string s;
    cin >> n >> k >> s;
    uk1 = 0;
    uk2 = 1;
    while (s[uk1] == '1')
        uk1++;
    q[sz++] = uk1;
    uk2 = uk1 + 1;
    while (sz < k + 1) {
        while (uk2 < n && s[uk2] == '1')
            uk2++;
        q[sz++] = uk2;
        uk2++;
    }
    int ans = n + 1;
    int mid = (st + (sz - 1)) / 2;
    while (uk2 <= n) {
        for (int k = 0; k <= sqrt(n) + 1; k++) {
            int r1 = mid;
            int r2 = mid + k;
            int r3 = mid - k;
            if (r3 >= st)
                ans = min(ans, max(abs(q[st] - q[r3]), abs(q[sz - 1] - q[r3])));
            if (r2 < sz)
                ans = min(ans, max(abs(q[st] - q[r2]), abs(q[sz - 1] - q[r2])));
        }
        st++;
        while (uk2 < n && s[uk2] == '1')
            uk2++;
        mid++;
        q[sz++] = uk2;
        uk2++;
    }
    cout << ans << endl;
}