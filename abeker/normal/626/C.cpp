#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    int lo = 0, hi = (int)1e8;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int two = max(N - mid / 2 + mid / 6, 0);
        int three = max(M - mid / 3 + mid / 6, 0);
        if (two + three > mid / 6) lo = mid + 1;
        else hi = mid; 
    }
    printf("%d\n", lo);
    return 0;
}