#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> par;

const int MAXN = 100005;
const int LOG = 30;

int N, M;
int a[LOG][MAXN];
vector < par > V[LOG];
int sol[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    while (M--) {
        int l, r, q;
        scanf("%d%d%d", &l, &r, &q);
        for (int i = 0; i < LOG; i++) 
            if ((q >> i) & 1) {
                a[i][l]++;
                a[i][r + 1]--;
            }
            else V[i].push_back(par(l, r));
    }
}

void solve() {
    for (int i = 0; i < LOG; i++) {
        for (int j = 1; j <= N; j++)
            a[i][j] += a[i][j - 1];
        for (int j = 1; j <= N; j++) 
            a[i][j] = a[i][j - 1] + (a[i][j] > 0);
        for (int j = 0; j < V[i].size(); j++) {
            int l = V[i][j].first, r = V[i][j].second;
            if (a[i][r] - a[i][l - 1] == r - l + 1) { puts("NO"); return; }
        }
        for (int j = 1; j <= N; j++) 
            if (a[i][j] > a[i][j - 1]) sol[j] |= 1 << i;
    }
    puts("YES");
    for (int i = 1; i <= N; i++)
        printf("%d ", sol[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}