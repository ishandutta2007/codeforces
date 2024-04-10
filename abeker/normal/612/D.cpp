#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

int N, K;
vector <pii> V, sol;

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        V.push_back(pii(l, 0));
        V.push_back(pii(r, 1));
    }
}

void solve() {
    sort(V.begin(), V.end());
    int cnt = 0, last = 0;
    for (int i = 0; i < V.size(); i++)
        if (V[i].second) {
            if (cnt == K) 
                sol.push_back(pii(last, V[i].first));
            cnt--;
        }
        else {
            if (cnt == K - 1) 
                last = V[i].first;
            cnt++;
        }

    printf("%d\n", sol.size());
    for (int i = 0; i < sol.size(); i++)
        printf("%d %d\n", sol[i].first, sol[i].second);
}

int main() {
    load();
    solve();
    return 0;
}