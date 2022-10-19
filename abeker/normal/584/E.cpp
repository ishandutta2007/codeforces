#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2005;

int N;
int p[MAXN], pos[MAXN];
set <int> ones, zeroes;
vector <pii> sol;

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", p + i);
    for (int i = 1; i <= N; i++) {
        int x; 
        scanf("%d", &x);
        pos[x] = i;
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        p[i] = pos[p[i]];
        if (p[i] > i) ones.insert(i);
        if (p[i] < i) zeroes.insert(i);
    }
    
    int res = 0;
    while (!ones.empty() && !zeroes.empty()) {
        int tmp = *(--ones.end());
        int nxt = *zeroes.lower_bound(tmp);
        ones.erase(tmp);
        zeroes.erase(nxt);
        if (p[tmp] != nxt) ones.insert(nxt);
        if (p[nxt] != tmp) zeroes.insert(tmp);
        swap(p[tmp], p[nxt]);
        sol.push_back(pii(tmp, nxt));
        res += nxt - tmp;
    }
    
    printf("%d\n%d\n", res, sol.size());
    for (int i = 0; i < sol.size(); i++)
        printf("%d %d\n", sol[i].first, sol[i].second);
}

int main() {
    load();
    solve();
    return 0;
}