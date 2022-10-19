#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

const int MAXN = 505;

int N;
multiset <int> S;
int a[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N * N; i++) {
        int x;
        scanf("%d", &x);
        S.insert(x);
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        a[i] = *(--S.end());
        for (int j = 0; j < i; j++) 
            for (int k = 0; k < 2; k++)
                S.erase(S.find(__gcd(a[i], a[j])));
        S.erase(S.find(__gcd(a[i], a[i])));
        printf("%d ", a[i]);
    }
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}