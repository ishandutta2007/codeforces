#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

int n, m, k;
int rCol[N], cCol[N];
int rTime[N], cTime[N];

int main (int argc, char const *argv[]) {
    scanf("%d %d %d", &m, &n, &k);
    for (int t = 1; t <= k; ++t) {
        int cmd, x, y;
        scanf("%d %d %d", &cmd, &x, &y);
        
        if (cmd == 1) {
            rCol[x] = y;
            rTime[x] = t;
        } else {
            cCol[x] = y;
            cTime[x] = t;
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (rTime[i] > cTime[j]) printf("%d ", rCol[i]);
            else printf("%d ", cCol[j]);
        }
        puts("");
    }
    return 0;
}