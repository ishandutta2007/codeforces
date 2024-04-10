#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n, A[111];

void Do(int x, int y = 0) {
    if(x > n) {
        if(y % 360 == 0) {
            puts("YES");
            exit(0);
        }
        return;
    }
    Do(x + 1, y + A[x]);
    Do(x + 1, y - A[x]);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
    Do(1);
    puts("NO");
    return 0;
}