#include <bits/stdc++.h>

using namespace std;

int f[1001];
int c[1001];

int main() {
    int n;
    vector <int> a;
    int ans = 0;
    scanf("%d", &n);
    a.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++) {
        f[c[a[i]]++]++;
    }
    for (int i = 0; i <= 1000; i++)
        ans += (f[i] - (f[i] > 0));
    printf("%d\n", ans);
}