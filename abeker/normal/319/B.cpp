#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

const int MAXN = 100005;
const int offset = 1 << 17;

int N;
int a[MAXN];
int t[2 * offset];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

void update(int x, int val) {
    x += offset;
    t[x] = val;
    for (x /= 2; x; x /= 2) 
        t[x] = max(t[2 * x], t[2 * x + 1]);
}

int query(int x, int lo, int hi, int from, int to) {
    if (lo >= to || hi <= from) return 0;
    if (lo >= from && hi <= to) return t[x];
    int mid = (lo + hi) / 2;
    return max(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

int solve() {
    stack <int> S;
    int sol = 0;
    for (int i = 0; i < N; i++) {
        while (!S.empty() && a[i] > a[S.top()])
            S.pop();
        int dp = S.empty() ? 0 : query(1, 0, offset, S.top() + 1, i) + 1;
        update(i, dp);
        sol = max(sol, dp);
        S.push(i);
    }
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}