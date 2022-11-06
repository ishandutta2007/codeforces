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
const int V = 100100;
const int N = 100;
int cnt[1200];
char s[V];
int n;
LL T;

int main() {
    while (~scanf("%d%lld", &n, &T)) {
        scanf("%s", s);
        T -= 1 << (s[n - 1] - 'a');
        T += 1 << (s[n - 2] - 'a');
        n -= 2;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) cnt[s[i] - 'a' + 1]++;
        for (int i = 0; i < n; ++i) T += 1 << (s[i] - 'a');
        for (int i = 0; i < N; ++i) {
            if (cnt[i] > 2) {
                cnt[i + 1] += (cnt[i] - 1) / 2;
                cnt[i] = (cnt[i] - 1) % 2 + 1;
            }
        }
        bool ok = true;
        for (int i = 0; i < N; ++i) {
            if (T % (1LL << (i + 1)) != 0) {
                if (cnt[i] == 0) ok = false;
                else cnt[i]--, T -= 1LL << i;
            }
            if (cnt[i] >= 2) cnt[i + 1]++;
        }
        if (T != 0LL) ok = false;
        if (ok) puts("Yes");
        else puts("No");
    }
    return 0;
}

/*
2 -1
ba
3 1
abc
3 3
abc
3 -7
abc
7 -475391
qohshra
*/