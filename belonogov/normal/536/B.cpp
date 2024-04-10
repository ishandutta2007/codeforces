#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const int INF = 1e9;
const int ALF = 26;
const int MOD = 1e9 + 7;

int n, m;
int len;
char s[N];
int z[N];
int pos[N];

void zf() {
    int l = 0, r = 0;
    len = strlen(s);
    for (int i = 1; i < len; i++) {
        if (r > i) 
            z[i] = min(r - i, z[i - l]);
        for (; i + z[i] < len && s[z[i]] == s[i + z[i]]; z[i]++);
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
}

void read() {
    scanf("%d%d", &n, &m);
    scanf("%s", s); 
    for (int i = 0; i < m; i++) {
        scanf("%d", &pos[i]); 
        pos[i]--;
    }
}

void solve() {
    zf();
    //for (int i = 0; i < len; i++)
        //cerr << z[i] << " ";
    //cerr << endl;
    bool flag = 1;
    int cntFree = 0;
    int cur = 0;
    for (int i = 0; i < m; i++) {
        if (pos[i] > cur)
            cntFree += pos[i] - cur;
        cur = pos[i] + len;
    }
    cntFree += n - cur;
    for (int i = 0; i < m - 1; i++) {
        int dist = pos[i + 1] - pos[i];
        if (dist < len)
            flag &= z[dist] + dist == len;
    }
    int ans = 1;
    if (flag) {
        for (int i = 0; i < cntFree; i++)
            ans = (ans * 1ll * ALF) % MOD;
    }
    else
        ans = 0;
    printf("%d\n", ans);
}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}