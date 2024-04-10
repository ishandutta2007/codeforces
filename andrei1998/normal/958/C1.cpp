#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100000 + 5;

int N, p;
int A[NMAX];

inline void upd(int &where, int val) {
    if (val > where)
        where = val;
}

int main() {
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);

    cin >> N >> p;
    for (int i = 1; i <= N; ++ i)
        cin >> A[i];

    int sum = 0;
    for (int i = 1; i <= N; ++ i)
        sum = (sum + A[i]) % p;

    int ans = -1;
    int sum_pref = 0;
    int sum_suf = 0;
    for (int i = 1; i < N; ++ i) {
        sum_pref = (sum_pref + A[i]) % p;
        sum_suf = (sum - sum_pref) % p;
        if (sum_suf < 0)
            sum_suf += p;
        upd(ans, sum_pref + sum_suf);
    }

    cout << ans << '\n';
    return 0;
}