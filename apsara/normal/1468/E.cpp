#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a[4];
    scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
    sort(a, a + 4);
    printf("%d\n", a[0] * a[2]);
}

int main(){
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}