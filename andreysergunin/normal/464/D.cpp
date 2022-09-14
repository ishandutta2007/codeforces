#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

const int MAXM = 1000;

int main() {
    int n, k;
    cin >> n >> k;
    double dpPrev[MAXM + 1];
    double dpNext[MAXM + 1];
    
    for (int i = 0; i <= min(MAXM - 1, n); i++)
        dpPrev[i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(MAXM - 1, n); j++)
            dpNext[j] = (j * dpPrev[j] + dpPrev[j + 1] + j * (j + 3) / 2) / (k * (j + 1))
                                + (double)(k - 1) / k * dpPrev[j];
        for (int j = 0; j <= min(MAXM - 1, n); j++)
            dpPrev[j] = dpNext[j];
    }
    printf("%.12lf", k * dpPrev[1]);
    return 0;
}