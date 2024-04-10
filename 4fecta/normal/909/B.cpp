#include <bits/stdc++.h>
using namespace std;
int n, a[105];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int lay = 1;
        for (int j = n; j >= i; j--) {
            a[j] += lay++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, a[i]);
    printf("%d\n", ans);
}