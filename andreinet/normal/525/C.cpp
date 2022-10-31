#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 100005, Vmax = 1000006;

int A[Nmax];
int Count[Vmax];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        Count[A[i]]++;
    }

    i64 ans = 0;
    int last = -1;
    bool ok = false;
    for (int i = Vmax - 6; i > 0; --i) {
        if (last != -1) {
            if (Count[i] >= 2) {
                ans += 1LL * last * i;
                Count[i] -= 2;
                last = -1;
                ok = false;
            }
        }

        if (Count[i] > 4) ok = false;
        ans += 1LL * (Count[i] / 4) * i * i;
        Count[i] %= 4;

        if (Count[i] >= 2) last = i;
        if (Count[i] % 2) {
            if (!ok || Count[i] > 1) {
                Count[i - 1]++;
                ok = true;
            } else ok = false;
        } else ok = false;
    }

    cout << ans << '\n';
}