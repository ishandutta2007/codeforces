#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define long int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

int sieve[500500];
int a[200500];
bool used[200500];
int cnt[500500];
long total;

void update(int *d, int i, int x, int sign) {
    if (i < 0) {
        cnt[x] += sign;
        return;
    }
    update(d, i - 1, x, sign);
    update(d, i - 1, x * d[i], sign);
}

int count(int *d, int i, int x) {
    if (i < 0) {
        return cnt[x];
    }
    return count(d, i - 1, x) - count(d, i - 1, x * d[i]);
}

void update(int x, int sign) {
    int d[20], m = 0;
    for (; x > 1; ) {
        int p = sieve[x];
        do x /= p; while (x % p == 0);
        d[m++] = p;
    }
    if (sign > 0)
        total += count(d, m - 1, 1);
    update(d, m - 1, 1, sign);
    if (sign < 0)
        total -= count(d, m - 1, 1);
}

int main() {
    for (int p = 2; p < 500500; ++p)
        if (sieve[p] == 0) {
            sieve[p] = p;
            for (int x = 2 * p; x < 500500; x += p)
                sieve[x] = p;
        }
    int n, q;
    scanf("%d%d", &n, &q);
    REP (i, n) {
        scanf("%d", a + i);
    }
    for (int i; q --> 0; ) {
        scanf("%d", &i);
        --i;
        if (used[i] ^= 1) {
            update(a[i], +1);
        } else {
            update(a[i], -1);
        }
        cout << total << endl;
    }
    return 0;
}