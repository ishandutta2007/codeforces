#include <cstdio>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

int N;
char a[MAXN], b[MAXN];

void load() {
    scanf("%d%s%s", &N, a, b);
}

double solve() {
    double tot = 0;
    for (int j = 0; j < 26; j++) {
        int pref_a = 0, pref_b = 0;
        ll sum_a = 0, sum_b = 0;
        for (int i = 0; i < N; i++) {
            pref_a += a[i] == 'A' + j;
            pref_b += b[i] == 'A' + j;
            tot += (double)pref_a * pref_b;
            tot -= (double)((ll)pref_a * sum_b + (ll)pref_b * sum_a) / N;
            sum_a += (ll)pref_a;
            sum_b += (ll)pref_b;       
        }  
    }
    return 6 * tot / (N + 1) / (2 * N + 1);
}

int main() {
    load();
    printf("%.9lf\n", solve());
    return 0;
}