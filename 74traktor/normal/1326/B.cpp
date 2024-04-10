#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int b[maxn], a[maxn], x[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set < int > Q;
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) {
        a[i] = b[i] + x[i];
        x[i + 1] = max(x[i], a[i]);
    }
    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    return 0;
}