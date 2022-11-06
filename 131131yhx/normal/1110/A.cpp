#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int b, k;
    scanf("%d%d", &b, &k), b %= 2;
    int ans = 0;
    for(int i = 1, tmp = 1; i <= k; i++) {
        int x;
        scanf("%d", &x);
        ans = (ans * b + x);
    }
    if(ans & 1) puts("odd"); else puts("even");
    return 0;
}