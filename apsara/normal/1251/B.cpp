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
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 60;
char s[V];
int cnt[2], a[V], _, n;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        bool odd = false;
        for (int i = 0; i < n; ++i) {
            scanf("%s", s);
            a[i] = strlen(s);
            for (int j = 0; j < a[i]; ++j)
                cnt[s[j] - '0']++;
            if (a[i] % 2 == 1) odd = true;
        }
        int ans = n;
        if (!odd && cnt[0] % 2 == 1) --ans;
        printf("%d\n", ans);
    }
    return 0;
}

/*
4
1
0
3
1110
100110
010101
2
11111
000001
2
001
11100111

*/