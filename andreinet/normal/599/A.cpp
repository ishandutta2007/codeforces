#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;

    int ans = 0x3f3f3f3f;
    ans = min(ans, d1 + d2 + d3);
    ans = min(ans, d1 + d1 + d2 + d2);
    ans = min(ans, d1 + d3 + d3 + d1);
    ans = min(ans, d2 + d3 + d3 + d2);
    
    cout << ans << '\n';
}