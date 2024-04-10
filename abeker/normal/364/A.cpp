#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const int MAXN = 4005;
const int MAXM = 36005;

int N, A;
char s[MAXN];
int cnt[MAXM];

void load() {
    scanf("%d%s", &A, s);
}

ll solve() {
    N = strlen(s);
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = i; j < N; j++) {
            sum += s[j] - '0';
            cnt[sum]++;
        }
    }
    
    if (!A) {
        int tot = N * (N + 1) / 2;
        return (ll)cnt[0] * (2 * tot - cnt[0]);
    }
    
    ll sol = 0;
    for (int i = 1; i < MAXM; i++)
        if (!(A % i) && A / i < MAXM) sol += (ll)cnt[i] * cnt[A / i];
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}