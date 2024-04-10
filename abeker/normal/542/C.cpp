#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 205;

int N;
int f[MAXN];
int bio[MAXN];
ll lcm = 1, maks;

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) 
        scanf("%d", f + i);
}

void go(int x) {
    memset(bio, -1, sizeof bio);
    int i = 0;
    for (; bio[x] == -1; i++) {
        bio[x] = i;
        x = f[x];
    }
    int cycle = i - bio[x];
    lcm *= (ll)cycle / __gcd((ll)cycle, lcm);
    maks = max(maks, (ll)bio[x]);
}

ll solve() {
    for (int i = 1; i <= N; i++) 
        go(i);
    maks = max(maks, lcm);
    return maks + (lcm - maks % lcm) % lcm;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}