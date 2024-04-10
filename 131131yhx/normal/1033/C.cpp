#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>

using namespace std;

int n, A[211111], W[211111], F[211111];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]), W[A[i]] = i;
    for(int i = n; i >= 1; i--) {
        int w = W[i];
        F[w] = 0;
        for(int j = w - i; j >= 1; j -= i)
            if(A[j] > i && F[j] == 0) {
                F[w] = 1;
                break;
            }
        for(int j = w + i; j <= n; j += i)
            if(A[j] > i && F[j] == 0) {
                F[w] = 1;
                break;
            }
    }
    for(int i = 1; i <= n; i++) putchar(1 - F[i] + 'A');
    return 0;
}