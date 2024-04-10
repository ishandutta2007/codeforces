#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 100005;
const int MAXM = 2000005;

int N, A, B;
int x[MAXN];
int maks[MAXM];
vector <int> V[MAXM];
set <int> S;
int nxt[MAXM];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", x + i);
    scanf("%d%d", &A, &B);
}

int solve() {
    sort(x, x + N);
    N = unique(x, x + N) - x;
    for (int i = 0; i < N; i++)
        for (int pos = B + (x[i] - B % x[i]) % x[i]; pos <= A; pos += x[i])
            maks[pos - B] = max(maks[pos - B], x[i]);
    
    for (int i = 0; i <= A - B; i++) {
        for (int j = 0; j < V[i].size(); j++) 
            S.erase(V[i][j]);
        if (maks[i]) S.insert(i);
        if (i + maks[i] <= A - B)
            V[i + maks[i]].push_back(i);
        nxt[i] = i - 1;
        if (!S.empty()) 
            nxt[i] = min(nxt[i], *S.begin());
    }
    
    int sol = 0;
    for (A -= B; A > 0; A = nxt[A])
        sol++;
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}