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

const int V = 1001000;

char s[V];

int _, x;


int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &x);
        scanf("%s", s);
        int n = strlen(s);
        int cur = n;
        for (int pos = 1; pos <= x; ++pos) {
            int cl = (n - pos + P) % P;
            int t = s[pos - 1] - '0';
            //printf("POS %d %d %d\n", pos, cl, t);
            n += (LL) (t - 1) * cl % P;
            n %= P;
            for (int i = 1; i < t && cur < x; ++i) {
                for (int j = 0; j < cl && cur < x; ++j) {
                    s[cur++] = s[pos + j];
                }
            }
            //for (int i = 0; i < n; ++i) printf("%c", s[i]);puts("");
        }
        printf("%d\n", n);
    }
    return 0;
}

/*
4
5
231
7
2323
6
333
24
133321333
*/