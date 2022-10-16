#include <bits/stdc++.h>

// 5:11
using namespace std;

const int NMAX = 1000000 + 5;
typedef long long int lint;

int N;
lint sumA;
int a[2 * NMAX];

int ext[NMAX], where[NMAX], steps[NMAX];

int solve(lint D) {
    if (D >= sumA)
        return 1;

    int j = 0;
    lint sum = 0;
    for (int i = 1; i <= N; ++ i) {
        if (j + 1 == i)
            j = i, sum = a[i];
        while (j + 1 <= 2 * N && sum + a[j + 1] <= D)
            ++ j, sum += a[j];
        ext[i] = j;
        sum -= a[i];
    }

    for (int i = N; i >= 1; -- i)
        if (ext[i] >= N)
            where[i] = ext[i], steps[i] = 1;
        else
            where[i] = where[ext[i] + 1], steps[i] = 1 + steps[ext[i] + 1];

    int ans = N;
    for (int i = 1; i <= N; ++ i)
        if (where[i] >= N + i - 1)
            ans = min(ans, steps[i]);
    return ans;
}

int main() {
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    int Q = 0;
    cin >> N >> Q;
    for (int i = 1; i <= N; ++ i) {
        cin >> a[i];
        sumA += a[i];
        a[N + i] = a[i];
    }

    while (Q --) {
        lint D;
        cin >> D;
        cout << solve(D) << endl;
    }
    return 0;
}