#include <bits/stdc++.h>

using namespace std;

const int N = 3010;
const int INF = 1e9 + 10;

struct data {
    int rank, prog, sport;
    bool operator < (const data &d) const {
        return prog > d.prog;
    }
};

data x[N];
int n, p, s, dp[N][N], pre[N][N];
vector <int> progs, sports;

int call (int pos, int sport) {
    if (sport > pos) return -INF;
    if (pos == 0) return 0;
    if (dp[pos][sport] != -1) return dp[pos][sport];

    int &ret = dp[pos][sport];
    ret = 0;

    if (sport and x[pos].sport + call(pos - 1, sport - 1) > ret) {
        ret = x[pos].sport + call(pos - 1, sport - 1);
        pre[pos][sport] = 1;
    }

    if (p + sport >= pos) {
        if (x[pos].prog + call(pos - 1, sport) > ret) {
            ret = x[pos].prog + call(pos - 1, sport);
            pre[pos][sport] = -1;
        }
    } else {
        if (call(pos - 1, sport) > ret) {
            ret = call(pos - 1, sport);
            pre[pos][sport] = -1;
        }
    } 

    return ret;
}

int main (int argc, char const *argv[]) {
    scanf("%d %d %d", &n, &p, &s);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x[i].prog);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x[i].sport);
        x[i].rank = i;
    }
    sort(x + 1, x + n + 1);
    memset(dp, -1, sizeof dp);
    memset(pre, -1, sizeof pre);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= s; ++j)
            call(i, j);

    for (int pos = n, sport = s; pos; --pos) {
        if (pre[pos][sport] == 1) sports.push_back(x[pos].rank), --sport; 
        else if (p + sport >= pos) progs.push_back(x[pos].rank);
    }

    printf("%d\n", call(n, s));
    for (int i = 0; i < p; ++i) printf("%d ", progs[i]); puts("");
    for (int i = 0; i < s; ++i) printf("%d ", sports[i]); puts("");
    return 0;
}