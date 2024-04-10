#include <bits/stdc++.h>
using namespace std;
int n, k, a[1000005];
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    deque<int> dq;
    for (int i = 1; i <= n; i++) dq.push_back(a[i]);
    int ans = n;
    for (int i = 1; i <= n; i++) {
        while (dq.front() < a[i] - k) dq.pop_front();
        while (dq.front() < a[i]) dq.pop_front(), ans--;
    }
    printf("%d\n", ans);
}