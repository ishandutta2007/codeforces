#include <bits/stdc++.h>
using namespace std;

int a[10];
void solve() {
    int n = 4;
    for (int i = 1; i <= n ; ++i)
        scanf("%d", &a[i]);

    int cnt = (a[1] + a[2]) % 2;
    if (cnt == 0) {
        printf("Tidak Tidak ");
        if (a[3] > 0 || a[2] > 0) printf("Ya ");
        else printf("Tidak ");
        if (a[1] > 0 || a[4] > 0) printf("Ya ");
        else printf("Tidak ");
    } else {
        if (a[1] > 0 || a[4] > 0) printf("Ya ");
        else printf("Tidak ");
        if (a[3] > 0 || a[2] > 0) printf("Ya ");
        else printf("Tidak ");
        printf("Tidak Tidak ");
    }

    printf("\n");
}
int main()
{
    #ifdef HOME
    freopen("1.in", "r", stdin);
    #endif // HOME

    int t;
    scanf("%d", &t);
    while (t--) solve();

    return 0;
}