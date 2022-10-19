#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXM = 200005;

int D, N, M;
pii p[MAXM];
int nxt[MAXM];

void load() {
    scanf("%d%d%d", &D, &N, &M);
    for (int i = 0; i < M; i++)
        scanf("%d%d", &p[i].first, &p[i].second); 
}

ll solve() {
    sort(p, p + M);
    p[M].first = D;
    if (p[0].first > N) return -1;
    for (int i = 0; i < M; i++)
        if (p[i + 1].first - p[i].first > N) return -1;
    
    stack <int> S;
    S.push(M);
    for (int i = M - 1; i >= 0; i--) {
        while (p[S.top()].second >= p[i].second) S.pop();
        nxt[i] = S.top();
        S.push(i); 
    }
    
    int pos = 0;
    int gas = N - p[0].first;
    ll sol = 0;
    while (pos < M) {
        int dist = p[nxt[pos]].first - p[pos].first;
        if (dist <= N) {
            ll curr = max(dist - gas, 0);
            sol += (ll)curr * p[pos].second;
            pos = nxt[pos];
            gas += curr - dist;
            continue;
        }
        sol += (ll)(N - gas) * p[pos].second;
        gas = N + p[pos].first - p[pos + 1].first;
        pos++;
    }
    
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}