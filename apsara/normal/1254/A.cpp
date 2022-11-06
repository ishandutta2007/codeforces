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

const int V = 110;
char s[V][V];
char ans[V][V];

char res(int i) {
    if (i < 26) return i + 'a';
    else if (i < 52) return (i - 26) + 'A';
    else return (i - 52) + '0';
}
int _, n, m, K;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d%d", &n, &m, &K);
        for (int i = 0; i < n; ++i) scanf("%s", s[i]);
        int rn = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == 'R') ++rn;
            }
        }
        int mi = rn / K;
        int mx = mi + 1;
        int f = K - rn % K;
        //printf("%d %d %d\n", mi, mx, f);
        int cur = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            int st = 0, ed = m, df = 1;
            if (i % 2 == 1) st = m - 1, ed = -1, df = -1;
            for (int j = st; j != ed; j += df) {
                if (s[i][j] == 'R') {
                    ++cnt;
                    if (cur < f) {
                        if (cnt > mi) {
                            ++cur;
                            cnt = 1;
                        }
                    } else {
                        if (cnt > mx) {
                            ++cur;
                            cnt = 1;
                        }
                    }
                }
                ans[i][j] = res(cur);
            }
        }
        for (int i = 0; i < n; ++i, puts(""))
            for (int j = 0; j < m; ++j)
                printf("%c", ans[i][j]);
    }
    return 0;
}

/*
4
3 5 3
..R..
...R.
....R
6 4 6
R..R
R..R
RRRR
RRRR
R..R
R..R
5 5 4
RRR..
R.R..
RRR..
R..R.
R...R
2 31 62
RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
*/