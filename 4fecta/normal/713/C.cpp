#include <bits/stdc++.h>
using namespace std;
int n, a[3005];
long long ans;
priority_queue<int> q;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
        if (q.size() && q.top() > a[i]) ans += q.top() - a[i];
        q.push(a[i]), q.push(a[i]);
        q.pop();
    }
    printf("%lld\n", ans);
}