#include <cstdio>
using namespace std;

typedef long long ll;

const int MAXN = 100005;
const int offset = 1 << 17;

int N;
int a[MAXN];
ll dp[MAXN];
int t[2 * offset];

void load() {
    scanf("%d", &N);
    for (int i = 1; i < N; i++) 
        scanf("%d", a + i);
}

int merge(int l, int r) {
    return a[l] > a[r] ? l : r;
}

int query(int x, int lo, int hi, int from, int to) {
    if (lo >= to || hi <= from) return 0;
    if (lo >= from && hi <= to) return t[x];
    int mid = (lo + hi) / 2;
    return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to)); 
}

ll solve() {
    a[N] = 1;
    for (int i = 1; i <= N; i++)
        t[i + offset] = i;
    for (int i = offset - 1; i >= 0; i--)
        t[i] = merge(t[2 * i], t[2 * i + 1]);
        
    ll sol = 0;
    for (int i = N - 1; i; i--) {
        int pos = query(1, 0, offset, i + 1, a[i] + 1);
        dp[i] = dp[pos] + pos + N - a[i] - i;
        sol += dp[i];
    }
    
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}