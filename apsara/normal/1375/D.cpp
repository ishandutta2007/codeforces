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
const int V = 1010;
int a[V], cnt[V],ans[V *2];
int _, n, m;

int cm() {
    int mx = 0;
    for (int i = 0; i <= n; ++i) if(cnt[i] == 0) {mx = i; break;}
    return mx;
}

void mex(int pos) {
    int mx = 0;
    for (int i = 0; i <= n; ++i) if(cnt[i] == 0) {mx = i; break;}
    cnt[a[pos]]--;
    a[pos] = mx;
    cnt[a[pos]]++;
    ans[m++] = pos;
}

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        memset(cnt, 0, sizeof(cnt));
        m = 0;
        for (int i = 0; i < n; ++i) cnt[a[i]]++;
        //for (int i = 0; i < n; ++i) if (cnt[a[i]] > 1) mex(i);
        while (1) {
            int mx = cm();
            if (mx == n) break;
            mex(mx);
        }
        //for (int i = 0; i < n; ++i) printf("%d ", a[i]); puts("");

        for (int i = 0; i < n; ++i) {
            if (a[i] != i) {
                for (int j = i + 1; j < n;++j) {
                    if (a[j] == i) mex(j);
                }
                mex(i);
            }
        }
        /*
        int st = 0;
        while (1) {
            int mx = cm();
            if (mx == n) {
                if(st == 1) break;
                else {++st, mex(n - 1);}
            } else {
                mex(mx);
            }
        }*/
        printf("%d\n", m);
        for (int i = 0; i < m; ++i) printf("%d ", ans[i] + 1); puts("");
        //for (int i = 0; i < n; ++i) printf("%d ", a[i]); puts("");
    }
    return 0;
}

/*
5
3
2 2 3
3
2 1 0
7
0 7 3 1 3 7 7
9
2 0 1 1 2 4 4 2 0
9
8 4 7 6 1 2 3 0 5
*/