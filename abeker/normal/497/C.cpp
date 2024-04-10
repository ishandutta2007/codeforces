#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;

int N, M;
int a[MAXN][2], b[MAXN][2];
int k[MAXN];
vector <pii> V;
set <pii> S;
int sol[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d", a[i], b[i]);
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
        scanf("%d%d%d", a[i] + 1, b[i] + 1, k + i);
}

bool cmp(const pii &l, const pii &r) {
    if (a[l.first][l.second] != a[r.first][r.second])
        return a[l.first][l.second] < a[r.first][r.second];
    return l.second > r.second;
}

void bye() {
    puts("NO");
    exit(0);
}

void solve() {
    for (int i = 0; i < N; i++)
        V.push_back(pii(i, 0));
    for (int i = 0; i < M; i++)
        V.push_back(pii(i, 1));
    sort(V.begin(), V.end(), cmp);
    
    for (int i = 0; i < V.size(); i++) 
        if (V[i].second) 
            S.insert(pii(b[V[i].first][1], V[i].first));
        else {
            if (S.empty()) bye();
            set <pii> :: iterator it = S.lower_bound(pii(b[V[i].first][0], -1));
            if (it == S.end()) bye();
            sol[V[i].first] = it -> second;
            if (--k[it -> second] == 0) S.erase(it);
        }
    
    puts("YES");
    for (int i = 0; i < N; i++)
        printf("%d ", ++sol[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;    
}