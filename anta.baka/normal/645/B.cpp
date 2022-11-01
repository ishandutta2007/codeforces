#include <stdio.h>
using namespace std;
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    long long ans = 0;
    int l = 0, r = n-1;
    for(int i = 0; i < k && l < r; i++) {
        ans += 2 * (r - l - 1) + 1;
        l++; r--;
    }
    printf("%I64d", ans);
    return 0;
}