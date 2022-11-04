#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int nw = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if(x > nw) {
            printf("%d\n", i);
            return 0;
        } else if(x == nw) nw++;
    }
    puts("-1");
    return 0;
}