#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

char ch1[12][12], tmp[12][12], ch2[12][12];

int n;

void equal() {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(ch1[i][j] != ch2[i][j]) return;
    puts("Yes");
    exit(0);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%s", ch1[i] + 1);
    for(int i = 1; i <= n; i++) scanf("%s", ch2[i] + 1);
    for(int T = 1; T <= 2; T++) {
        for(int i = 1; i <= 4; i++) {
            equal();
            for(int j = 1; j <= n; j++)
                for(int k = 1; k <= n; k++)
                    tmp[k][n - j + 1] = ch1[j][k];
            for(int j = 1; j <= n; j++)
                for(int k = 1; k <= n; k++)
                    ch1[j][k] = tmp[j][k];
        }
        for(int i = 1, j = n; i < j; i++, j--)
            swap(ch1[i], ch1[j]);
    }
    puts("No");
    return 0;
    
}