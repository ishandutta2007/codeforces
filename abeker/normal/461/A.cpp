#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 300005;

int N;
int a[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%d", a + i);
}

ll solve() {
    sort(a, a + N);
    ll sol = 0;
    for (int i = 0; i < N; i++)
        sol += (ll)(i + 2) * (ll)a[i];
    sol -= (ll)a[N - 1];
    return sol;
}

int main() {
    load();
    cout << solve() << endl;
    return 0;
}