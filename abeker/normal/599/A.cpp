#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int sum = 0, maks = 0;
    for (int i = 0; i < 3; i++) {
        int x; 
        scanf("%d", &x);
        sum += x;
        maks = max(maks, x);
    }
    printf("%d\n", min(sum, 2 * (sum - maks)));
    return 0;
}