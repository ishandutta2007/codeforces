#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pii;

const int MAXN = 100005;

int N;
vector <int> E[MAXN];
ll v[MAXN];

void load() {
       scanf("%d", &N);
       for (int i = 1; i < N; i++) {
               int a, b;
               scanf("%d%d", &a, &b);
               E[a].push_back(b);
               E[b].push_back(a);
       }
       for (int i = 1; i <= N; i++)
               scanf("%I64d", v + i);
}

pii dfs(int x, int p) {
       ll a = 0, b = 0;
       for (int i = 0; i < E[x].size(); i++) {
               int nxt = E[x][i];     
               if (nxt == p) continue;
               pii tmp = dfs(nxt, x);
               a = max(a, tmp.first);
               b = max(b, tmp.second);
       }
       ll add = b - a - v[x];
       if (add > 0) a += add;
       else b -= add;
       return pii(a, b);
}

ll solve() {
       pii sol = dfs(1, 0);
       return sol.first + sol.second;
}

int main() {
       load();
       printf("%I64d\n", solve());
       return 0;
}