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
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int N = 10;
char S[] = {"codeforces"};

LL n;
int ans[N];
int main() {
    while (~scanf("%lld", &n)) {
        for (int i = 0; i < N; ++i) ans[i] = 1;
        LL s = 1;
        while (s < n) {
            for (int i = 0; i < N && s < n; ++i) {
                s /= ans[i];
                ++ans[i];
                s *= ans[i];
            }
        }
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < ans[i]; ++j)
                putchar(S[i]);
        puts("");
    }
    return 0;
}

/*

*/