#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 200005;
const int MOD = 1000000007;

int N;
int a[MAXN];
int bio[MAXN];
int pot[MAXN];

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    else if (x < 0) x += MOD;
    return x;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i);
}

int dfs(int x) {
    vector <int> tmp;
    for (; !bio[x]; x = a[x]) {
        tmp.push_back(x);
        bio[x] = 1;
    }
    int memo = bio[x], pos = -1;
    for (int i = 0; i < tmp.size(); i++) {
        bio[tmp[i]] = 2;
        if (tmp[i] == x) pos = i;
    }
    return memo == 1 ? (int)tmp.size() - pos : 0;
}

int solve() {
    pot[0] = 1;
    for (int i = 1; i <= N; i++)
        pot[i] = add(pot[i - 1], pot[i - 1]);
     
    int rest = N, sol = 1;   
    for (int i = 1; i <= N; i++) {
        int cycle = dfs(i);
        rest -= cycle;
        if (cycle) sol = mul(sol, add(pot[cycle], -2));
    }
    sol = mul(sol, pot[rest]);
    
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}