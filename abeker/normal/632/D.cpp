#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1000005;

int N, M;
int a[MAXN];
int cnt[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

void solve() {
    M++;
    for (int i = 0; i < N; i++)
        if (a[i] < M) cnt[a[i]]++;
    
    for (int i = M - 1; i; i--)
        for (int j = 2 * i; j < M; j += i)
            cnt[j] += cnt[i];

    int lcm = max_element(cnt + 1, cnt + M) - cnt;
    vector <int> sol;
    for (int i = 0; i < N; i++)
        if (!(lcm % a[i])) sol.push_back(i);
    printf("%d %d\n", lcm, sol.size());
    for (int i = 0; i < sol.size(); i++)
        printf("%d ", ++sol[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}