#include <bits/stdc++.h>
 
using namespace std;

int n, m;

int main (int argc, char const *argv[]) {
    scanf("%d %d", &n, &m);
    
    int mini = n + n;
    for (int i = 1; i <= m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        mini = min(mini, r - l + 1);
    }
    
    printf("%d\n", mini);
    for (int i = 1, now = 0; i <= n; ++i, now = (now + 1) % mini) 
        printf("%d ", now);
    puts("");
    return 0;
}