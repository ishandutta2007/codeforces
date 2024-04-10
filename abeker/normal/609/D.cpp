#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 200005;

int N, M, K, S;
int a[MAXN], b[MAXN];
vector <pii> V[2];
ll pref[2][MAXN];

void load() {
    scanf("%d%d%d%d", &N, &M, &K, &S);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
    for (int i = 0; i < N; i++)
        scanf("%d", b + i);
    for (int i = 0; i < M; i++) {
        int t, c;
        scanf("%d%d", &t, &c);
        V[--t].push_back(pii(c, i + 1));
    }
}

int check(int d) {
    for (int i = 0; i < V[0].size() && i <= K; i++)
        if (K - i < (int)V[1].size() && (ll)a[d - 1] * pref[0][i] + (ll)b[d - 1] * pref[1][K - i] <= (ll)S)
            return i;
    return -1;
}

void solve() {
    for (int i = 1; i < N; i++) {
        a[i] = min(a[i], a[i - 1]);
        b[i] = min(b[i], b[i - 1]);
    }
    
    for (int i = 0; i < 2; i++) {
        V[i].push_back(pii(0, 0));
        sort(V[i].begin(), V[i].end());
        for (int j = 1; j < V[i].size(); j++)
            pref[i][j] = pref[i][j - 1] + (ll)V[i][j].first;
    }
    
    int lo = 1, hi = N;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid) != -1) hi = mid;
        else lo = mid + 1;
    }
    
    int tmp = check(lo);
    if (tmp == -1) {
        puts("-1");
        return;
    }
    
    printf("%d\n", lo);
    int d = min_element(a, a + lo) - a + 1;
    int p = min_element(b, b + lo) - b + 1;
    for (int i = 1; i <= tmp; i++)
        printf("%d %d\n", V[0][i].second, d);
    for (int i = 1; i <= K - tmp; i++)
        printf("%d %d\n", V[1][i].second, p);
}

int main() {
    load();
    solve();
    return 0;
}