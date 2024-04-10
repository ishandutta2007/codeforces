#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

const int MAXN = 100005;

int N;
int a[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

int solve() {
    stack <int> S;
    int sol = 0;
    for (int i = 0; i < N; i++) {
        for (; !S.empty() && a[i] > S.top(); S.pop())
            sol = max(sol, a[i] ^ S.top());
        if (!S.empty()) sol = max(sol, a[i] ^ S.top());
        S.push(a[i]);
    }
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}