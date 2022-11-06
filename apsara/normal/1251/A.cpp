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

char s[1200];
int ok[30], _;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%s", s);
        memset(ok, 0, sizeof(ok));
        int n = strlen(s);
        int cur = -1;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i != 0 && s[i] != s[i - 1]) {
                if (cnt % 2 == 1) ok[cur] = 1;
                cnt = 1;
            } else {
                cnt++;
            }
            cur = s[i] - 'a';
        }
        if (cnt % 2 == 1) ok[cur] = 1;
        for (int i = 0; i < 26; ++i) if (ok[i]) printf("%c", (i + 'a'));puts("");
    }
    return 0;
}

/*
4
a
zzaaz
ccff
cbddbb
*/