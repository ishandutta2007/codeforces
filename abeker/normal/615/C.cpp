#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2105;

char s[MAXN], t[MAXN];
int lcp[MAXN][MAXN][2];

void load() {
    scanf("%s%s", s, t);
}

void solve() {
    int N = strlen(s);
    int M = strlen(t);
    for (int k = 0; k < 2; k++) {
        for (int i = N - 1; i >= 0; i--) 
            for (int j = M - 1; j >= 0; j--)
                if (s[i] == t[j])
                    lcp[i][j][k] = lcp[i + 1][j + 1][k] + 1;
        reverse(s, s + N);
    }
    
    int pos = 0;
    vector <pii> sol;
    while (pos < M) {
        pii opt(0, 0);
        for (int k = 0; k < 2; k++)
            for (int i = 0; i < N; i++)
                if (lcp[i][pos][k] > lcp[opt.first][pos][opt.second])
                    opt = pii(i, k);
        int len = lcp[opt.first][pos][opt.second];
        if (!len) {
            puts("-1");
            return;
        }
        int lo = opt.first, hi = opt.first + len - 1;
        if (opt.second) {
            lo = N - lo - 1;
            hi = N - hi - 1;
        }
        sol.push_back(pii(lo, hi));
        pos += len;
    }
    
    printf("%d\n", sol.size());
    for (int i = 0; i < sol.size(); i++)
        printf("%d %d\n", ++sol[i].first, ++sol[i].second);
}

int main() {
    load();
    solve();
    return 0;
}