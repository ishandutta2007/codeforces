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
const int V = 200100;
char s[V], a[V], b[V];
int _, n;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%s", &n, s);
        int c0 = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (c0 & 1) {
                    a[i] = '(';
                    b[i] = ')';
                } else {
                    a[i] = ')';
                    b[i] = '(';
                }
                ++c0;
            }
        }
        bool ok = true;
        if (c0 & 1) ok = false;
        int c1 = n - c0;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (cur * 2 < c1) {
                    a[i] = b[i] = '(';
                } else {
                    a[i] = b[i] = ')';
                }
                ++cur;
            }
        }
        cur = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == '(') ++cur;
            else --cur;
            if (cur < 0) ok = false;
        }
        cur = 0;
        for (int i = 0; i < n; ++i) {
            if (b[i] == '(') ++cur;
            else --cur;
            if (cur < 0) ok = false;
        }
        a[n] = b[n] = 0;
        if (ok) {
            puts("YES");
            puts(a);
            puts(b);
        } else {
            puts("NO");
        }
    }
    return 0;
}

/*
3
6
101101
10
1001101101
4
1100
*/