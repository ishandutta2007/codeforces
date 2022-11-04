#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int n, A, B;

int main() {
    scanf("%d%d%d", &n, &A, &B);
    for(int i = 0; A * i <= n; i++)
        if(A * i <= n && (n - A * i) % B == 0) {
            int t = 1;
            for(int j = 1; j <= i; j++) {
                for(int k = t; k < t + A - 1; k++)
                    printf("%d ", k + 1);
                printf("%d ", t);
                t = t + A;
            }
            for(int j = 1; j <= (n - A * i) / B; j++) {
                for(int k = t; k < t + B - 1; k++)
                    printf("%d ", k + 1);
                printf("%d ", t);
                t += B;
            }
            return 0;
        }
    puts("-1");
    return 0;
}