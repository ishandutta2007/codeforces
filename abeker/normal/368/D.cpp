#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int MAXN = 200005;

int N, M, P;
int a[MAXN], b[MAXN];
vector <int> V[MAXN];
map <int, int> good, occ;
int cnt;

void load() {
    scanf("%d%d%d", &N, &M, &P);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
    for (int i = 0; i < M; i++)
        scanf("%d", b + i);
}

void add(int val, int d) {
    if (!good[val]) return;
    if (occ[val] == good[val]) cnt--;
    occ[val] += d;
    if (occ[val] == good[val]) cnt++;
}

void solve() {
    for (int i = 0; i < M; i++)
        good[b[i]]++;
    for (int i = 0; i < N; i++)
        V[i % P].push_back(a[i]);
    
    vector <int> sol;
    int sz = good.size();
    for (int i = 0; i < P; i++) {
        occ.clear();
        cnt = 0;
        for (int j = 0; j < V[i].size(); j++) {
            if (j >= M) add(V[i][j - M], -1);
            add(V[i][j], 1);
            if (cnt == sz) 
                sol.push_back(i + (j + 1 - M) * P);
        }
    }
    
    sort(sol.begin(), sol.end());
    printf("%d\n", sol.size());
    if (sol.empty()) return;
    for (int i = 0; i < sol.size(); i++)
        printf("%d ", ++sol[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}