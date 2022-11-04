#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int x;
        scanf("%d", &x);
        int tmp = x + 1;
        if((tmp & (-tmp)) != tmp) {
            while((tmp & (-tmp)) != tmp) tmp -= (tmp & (-tmp));
            printf("%d\n", tmp * 2 - 1);
            continue;
        }
        int ans = 1;
        for(int i = 2; i * i <= x; i++)
            if(x % i == 0) ans = max(ans, x / i);
        printf("%d\n", ans);
    }
    return 0;
}