#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;
    
const int MAXM = 100005;

int N, M;
int w[MAXM];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++)
        scanf("%*d%d", w + i);
}

int f(int k) {
    return k * (k - 1) / 2 + (k % 2 ? 1 : k / 2);
}

ll solve() {
    sort(w, w + M, greater <int> ());
    ll sol = 0;
    for (int i = 0; i < M && f(i + 1) <= N; i++) 
        sol += (ll)w[i];
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}