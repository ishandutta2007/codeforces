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

char s[V], t[V];
int ans[2 * V], n, m, _, N;

int st, L, R;


int get(int id) {
    if (st == 0) return L + id;
    else return R - id;
}

void rev(int id) {
    ans[m++] = id + 1;
    if (id == 0) {
        int x = get(0);
        s[x] = (s[x] - '0') ^ 1 + '0';
    } else {
        if (st == 0) {
            int tl = L;
            int tr = L + id;
            L = tl;
            R = tr;
        } else {
            int tl = R - id;
            int tr = R;
            L = tl;
            R = tr;
        }
        st ^= 1;
    }
}

int getc(int id) {
    int x = get(id);
    if (st == 0) return s[x];
    else return (s[x] - '0') ^ 1 + '0';
}


int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        scanf("%s%s", s, t);
        m = 0;
        N = n;
        st = 0;
        L = 0, R = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (getc(i) != t[i]) {
                if (getc(0) == t[i]) rev(0);
                rev(i);
            }
        }
        printf("%d", m);
        for (int i = 0; i < m; ++i) printf(" %d", ans[i]); puts("");
    }
    return 0;
}

/*
5
2
01
10
5
01011
11100
2
01
01
10
0110011011
1000110100
1
0
1
*/