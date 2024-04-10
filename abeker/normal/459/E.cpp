#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 300005; 

int N, M;
vector <int> E[MAXN];
int u[MAXN], v[MAXN], w[MAXN];
int maks[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", u + i, v + i, w + i);
        E[w[i]].push_back(i);
    }
}

int solve() {
    int sol = 0, bound = *max_element(w, w + M);
    for (int i = 1; i <= bound; i++) { 
        vector <int> tmp;
        for (vector <int> :: iterator it = E[i].begin(); it != E[i].end(); it++) 
            tmp.push_back(maks[u[*it]] + 1);
        for (; !E[i].empty(); E[i].pop_back(), tmp.pop_back()) {
            maks[v[E[i].back()]] = max(maks[v[E[i].back()]], tmp.back());
            sol = max(sol, maks[v[E[i].back()]]);
        }
    }
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}