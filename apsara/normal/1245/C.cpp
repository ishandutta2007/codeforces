#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long LL;
const int P = 1000000007;

const int V = 100100;
char s[V];

int fib[V];

int f(int len) {
    //printf("F %d %d\n", len, fib[len]);
    if (len < 2) return 1;
    return fib[len];
}

int main() {
    fib[0] = fib[1] = 1;
    for (int i = 2; i < V; ++i) fib[i] = (fib[i - 1] + fib[i - 2]) % P;
    while (~scanf("%s", s)) {
        int n = strlen(s);
        int ans = 1;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'm' || s[i] == 'w') ans = 0;
            if (s[i] == 'u' || s[i] == 'n') {
                if (i == 0 || s[i] == s[i - 1]) {
                    ++cur;
                } else {
                    ans = (LL) ans * f(cur) % P;
                    cur = 1;
                }
            } else {
                ans = (LL) ans * f(cur) % P;
                cur = 0;
            }
        }
        ans = (LL) ans * f(cur) % P;
        printf("%d\n", ans);
    }
    return 0;
}

/*
ouuokarinn
banana
nnn
amanda

*/