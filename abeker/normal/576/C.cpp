#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1000005;
const int MAXB = 1400;

int N;
int x[MAXN], y[MAXN];
vector <int> V[MAXB];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d", x + i, y + i);
}

bool cmp(const int &a, const int &b) {
    if (y[a] != y[b]) return y[a] < y[b];
    return x[a] < x[b];
}

void solve() {
    for (int i = 0; i < N; i++) 
        V[x[i] / MAXB].push_back(i);
    
    for (int i = 0; i < MAXB; i++) {
        sort(V[i].begin(), V[i].end(), cmp);
        for (int j = 0; j < V[i].size(); j++)
            printf("%d ", ++V[i][j]);
    }
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}