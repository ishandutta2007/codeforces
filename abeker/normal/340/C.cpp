#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100005;

int N;
int a[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

void output(ll x, ll y) {
    ll g = __gcd(x, y);
    printf("%I64d %I64d\n", x / g, y / g);
}

void solve() {
    sort(a, a + N);
    ll sum = 0, pref = 0;
    for (int i = 0; i < N; i++) {
        sum += (ll)i * (ll)a[i] - pref; 
        pref += a[i];
    }
    output(2 * sum + pref, (ll)N); 
}

int main() {
    load();
    solve();
    return 0;
}