#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

int N;
int a[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

ll solve() {
    int pos = min_element(a, a + N) - a;
    int curr = pos, last = pos;
    int sol = 0;
    for (int i = 0; i < N; i++) {
        if (a[curr] == a[pos]) last = curr;
        sol = max(sol, (last - curr + N) % N);
        curr = (curr + N - 1) % N;
    }
    return (ll)N * a[pos] + (ll)sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}