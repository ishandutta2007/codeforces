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

//RPS
int a[10];
char s[120];
char t[] = {"RPS"};
int ans[120];

int _, n;

int main() {
    map<char, int> mp;
    mp['R'] = 0;
    mp['P'] = 1;
    mp['S'] = 2;
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < 3; ++i) scanf("%d", &a[i]);
        scanf("%s", s);
        memset(ans, -1, sizeof(ans));
        for (int i = 0; i < n; ++i) {
            int id = (mp[s[i]] + 1) % 3;
            if (a[id] > 0) {
                ans[i] = id;
                a[id]--;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (ans[i] == -1) {
                for (int j = 0; j < 3; ++j) {
                    if (a[j] > 0) {
                        ans[i] = j;
                        --a[j];
                        break;
                    }
                }
            } else ++cnt;
        }
        if (cnt * 2 >= n) {
            puts("YES");
            for (int i = 0; i < n; ++i) printf("%c", t[ans[i]]); puts("");
        } else puts("NO");
    }
    return 0;
}

/*
2
3
1 1 1
RPS
3
3 0 0
RPS

*/