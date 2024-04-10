#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 200005;

int gcd(int a, int b) {
    int c;
    while (b) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

vector<int> lens[Nmax];
int A[Nmax];
bool isMax[2 * Nmax], used[Nmax];
int sums[Nmax];

void solve(int n, int len) {
    memset(used, 0, sizeof used);
    memset(isMax, 0, sizeof isMax);
    memset(sums, 0, sizeof sums);

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            int maxx = 0;
            for (int j = i; !used[j]; j = (j + len) % n) {
                used[j] = true;
                maxx = max(maxx, A[j]);
            }
            int ok = 1;
            for (int j = i; j != i || ok; j = (j + len) % n) {
                ok = 0;
                if (A[j] >= maxx) isMax[j] = true;
            }
        }
    }
    for (int i = n; i < 2 * n; ++i)
        isMax[i] = isMax[i - n];

    for (int i = 0, j = 0; i < n; ++i) {
        if (j < i) j = i;
        while (j - i < n && isMax[j]) ++j;
        if (j - i > 0) sums[j - i]++;
    }

    for (int i = n; i > 0; --i)
        sums[i] += sums[i + 1];
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> A[i];

    for (int i = 1; i < n; ++i)
        lens[gcd(i, n)].push_back(i);

    i64 ans = 0;
    for (int i = 1; i < n; ++i) {
        if (!lens[i].empty()) {
            solve(n, i);
            for (int p: lens[i])
                ans += sums[p];
        }
    }
    
    cout << ans << '\n';
}