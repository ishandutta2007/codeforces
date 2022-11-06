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
const int V = 110;
char s[V][V];
int use[V];
vector<int> res;
int n, m;
int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i)
            scanf("%s", s[i]);
        res.clear();
        memset(use, 0, sizeof(use));
        for (int i = 0; i < n; ++i) {
            if (use[i]) continue;
            int id = -1;
            for (int j = 0; j < n; ++j) {
                if (i == j || use[j]) continue;
                bool rev = true;
                for (int k = 0; k < m; ++k)
                    if (s[i][k] != s[j][m - 1 - k]) rev = false;
                if (rev) {id = j; break;}
            }
            if (id != -1) {
                use[i] = use[id] = -1;
                res.PB(i);
                res.PB(id);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (use[i]) continue;
            bool par = true;
            for (int k = 0; k < m; ++k)
                if (s[i][k] != s[i][m - 1 - k]) par = false;
            if (par) {res.PB(i); break;}
        }
        int L = res.size();
        printf("%d\n", m * res.size());
        for (int i = 0; i < max(L - 1, 0); i += 2) {
            for (int j = 0; j < m; ++j) printf("%c", s[res[i]][j]);
        }
        if (L % 2 == 1) {
            for (int j = 0; j < m; ++j) printf("%c", s[res[L - 1]][j]);
            --L;
        }
        for (int i = L - 1; i > 0; i -= 2) {
            for (int j = 0; j < m; ++j) printf("%c", s[res[i]][j]);
        }
        puts("");
    }
    return 0;
}

/*
3 3
tab
one
bat
4 2
oo
ox
xo
xx
3 5
hello
codef
orces
9 4
abab
baba
abcd
bcde
cdef
defg
wxyz
zyxw
ijji
*/