#include <iostream>
#include <cstdlib>
#include <set>

using namespace std;

int MOD;

int raise(int a, int b) {
    if (!b)
        return 1;
    else if (b & 1)
        return (1LL * a * raise(a, b - 1)) % MOD;
    else {
        int aux = raise(a, b >> 1);
        return (1LL * aux * aux) % MOD;
    }
}

int inv(int nr) {
    return raise(nr, MOD - 2);
}

int N;

int getSum(int a, int d) {
    int ans = ((2 * N - 1LL) * d) % MOD;
    ans = (1LL * ans * d) % MOD;
    ans = (1LL * ans * inv(6)) % MOD;
    ans = (1LL * ans + 1LL * a * d) % MOD;
    ans = (1LL * ans * (N - 1LL)) % MOD;
    ans = (1LL * ans + 1LL * a * a) % MOD;
    ans = (1LL * ans * N) % MOD;
    return ans;
}

set <int> Set;

const int NMAX = 100000 + 5;
int v[NMAX];

void doTry(int a, int d) {
    v[0] = a;
    for (int i = 1; i < N; ++ i) {
        v[i] = v[i - 1] + d;
        if (v[i] >= MOD)
            v[i] -= MOD;

        if (!Set.count(v[i]))
            return ;
    }

    cout << a << ' ' << d << '\n';
    exit(0);
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> MOD >> N;

    if (N == MOD) {
        cout << "0 1\n";
        return 0;
    }

    int sum = 0;
    int sum2 = 0;
    for (int i = 1; i <= N; ++ i) {
        int val;
        cin >> val;
        Set.insert(val);

        sum += val;
        if (sum >= MOD)
            sum -= MOD;
        sum2 = (sum2 + 1LL * val * val) % MOD;
    }

    for (auto it: Set) {
        int a = it;
        int d = ((2LL * sum * inv(N) + 2 * MOD - 2 * a) % MOD * inv(N - 1)) % MOD;

        if (MOD < 4)
            d = 1;

        if (MOD < 4 || getSum(a, d) == sum2)
            doTry(a, d);
    }

    cout << "-1\n";
    return 0;
}