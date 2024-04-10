#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;

const int MAXN = 500005;
const int LOG = 19;

int N;
char s[MAXN];
stack <int> S;
vector <int> pos[2 * MAXN];
int pref[MAXN];
int suff[MAXN];
int rank[LOG][MAXN];
int len[MAXN];
int it;

void load() {
    scanf("%d%s", &N, s);
}

bool cmp(int a, int b) {
    if (!it) return s[a] < s[b];
    if (rank[it - 1][a] != rank[it - 1][b])
        return rank[it - 1][a] < rank[it - 1][b];
    a += 1 << it - 1;
    b += 1 << it - 1;
    if (b >= N) return 0;
    if (a >= N) return 1;
    return rank[it - 1][a] < rank[it - 1][b];
}

int lcp(int a, int b) {
    int ret = 0;
    for (int i = LOG - 1; i >= 0; i--) {
        if (a + (1 << i) > N || b + (1 << i) > N) continue;
        if (rank[i][a] == rank[i][b]) {
            ret += 1 << i;
            a += 1 << i;
            b += 1 << i;
        }
    }
    return ret;
}

int get(char c) {
    return c == '(' ? 1 : -1;
}

int occ(int lo, int hi, int val) {
    val += MAXN;
    return max(upper_bound(pos[val].begin(), pos[val].end(), hi - 1) - upper_bound(pos[val].begin(), pos[val].end(), lo - 1), 0);
}

ll solve() {
    for (int i = 0; i < N; i++)
        suff[i] = i;
    
    for (it = 0; it < LOG; it++) {
        sort(suff, suff + N, cmp);
        for (int i = 1; i < N; i++)
            rank[it][suff[i]] = rank[it][suff[i - 1]] + cmp(suff[i - 1], suff[i]);
    }
    
    for (int i = 1; i < N; i++)
        len[suff[i]] = lcp(suff[i - 1], suff[i]);
    
    pref[0] = get(s[0]);
    for (int i = 1; i < N; i++) {
        pref[i] = pref[i - 1] + get(s[i]);
        pos[pref[i] + MAXN].push_back(i);
    }
    pref[N] = -MAXN;
    
    ll sol = 0;
    S.push(N);
    for (int i = N - 1; i >= 0; i--) {
        while (pref[S.top()] >= pref[i]) S.pop();
        sol += occ(i + 1 + len[i + 1], S.top(), pref[i]);
        S.push(i);
    }
    while (pref[S.top()] >= 0) S.pop();
    sol += occ(len[0], S.top(), 0);
    
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}