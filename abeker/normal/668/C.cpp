#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

typedef long double ld;

const int MAXN = 100005;
const ld eps = 1e-13;

int N;
ld pref[MAXN], suff[MAXN];
ld a[MAXN], b[MAXN];

ld get() {
    double x;
    scanf("%lf", &x);
    return x;
}

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) 
        pref[i] = get();
    for (int i = 1; i <= N; i++)
        suff[i] = get();
}

void solve() {
    for (int i = 1; i <= N; i++)
        pref[i] += pref[i - 1];
    for (int i = N; i; i--)
        suff[i] += suff[i + 1];
    
    for (int i = 1; i <= N; i++) {
        ld prod = pref[i];
        ld sum = pref[i] - suff[i + 1] + 1;
        ld diff = sqrt(sum * sum - 4 * prod + eps);
        a[i] = (sum + diff) / 2;
        b[i] = (sum - diff) / 2;
    }
    
    for (int i = 1; i <= N; i++)
        printf("%.10lf ", (double)(a[i] - a[i - 1]));
    puts("");
    
    for (int i = 1; i <= N; i++)
        printf("%.10lf ", (double)(b[i] - b[i - 1]));
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}