#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

int n;
int a[MAXN], b[MAXN];

inline int check(int val) { 
    int pos = lower_bound(b, b + n, a[val]) - b;
    return val + pos < n;
}
        
void solve() {
    for (int i = 0; i < n; i++)  
        printf("%d", (2 * i <= n - 2) | check(i));
    for (int i = 0; i < n; i++) 
        swap(a[i], b[i]);
    puts("");
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf("%d%d", &a[i], &b[i]);
    solve();
    solve();
    return 0;
}