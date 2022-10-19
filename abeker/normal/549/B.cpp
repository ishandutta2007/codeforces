#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 105;

int N;
char mat[MAXN][MAXN];
int a[MAXN], cnt[MAXN];
vector <int> sol;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%s", mat[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

int find() {
    for (int i = 0; i < N; i++)
        if (cnt[i] == a[i]) return i;
    return -1;
}

void add(int x) {
    for (int i = 0; i < N; i++)
        cnt[i] += mat[x][i] - '0';
}

void solve() {
    int tmp = find();
    if (tmp == -1) {
        printf("%d\n", sol.size());
        for (int i = 0; i < sol.size(); i++)
            printf("%d ", ++sol[i]);
        puts("");
        return;
    }
    sol.push_back(tmp);
    add(tmp);
    solve();
}

int main() {
    load();
    solve();
    return 0;
}