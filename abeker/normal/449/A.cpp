#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int N, M, K;

void load() {
    scanf("%d%d%d", &N, &M, &K);
}

ll solve() {
    K += 2;
    if (K > N + M) return -1;
    ll a = (ll)(N / max(K - M, 1)) * (ll)(M / (K - max(K - M, 1)));
    ll b = (ll)(M / max(K - N, 1)) * (ll)(N / (K - max(K - N, 1)));
    return max(a, b);
}

int main() {
    load();
    cout << solve() << endl;
    return 0;
}