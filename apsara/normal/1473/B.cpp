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
int _;
char s[120], t[120];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%s%s", s, t);
        int n = strlen(s);
        int m = strlen(t);
        int g = __gcd(n, m);
        int K = n * m / g;
        bool ok = true;
        for (int i = 0; i < K; ++i) if (s[i % n] != t[i % m]) ok = false;
        if (!ok) puts("-1");
        else {
            for (int i = 0; i < K; ++i) printf("%c", s[i % n]); puts("");
        }
    }
    return 0;
}

/*
3
baba
ba
aa
aaa
aba
ab
*/