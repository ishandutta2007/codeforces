#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

typedef long long i64;
const int Nmax = 500005;

string vowels = "IEAOUY";

double ec[Nmax];

void preprocess(int N) {
    ec[1] = 1;
    double p = 1;
    for (int i = 2; i <= N; ++i) {
        ec[i] = ec[i - 1] + p + 1.0D / i;
        p += 1.0D / i;
    }
}

double solve(int x) {
    if (x == 0) return 0;
    return ec[x];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    int N = S.length();

    preprocess(N);

    double ans = 0;
    for (int i = 0; i < N; ++i) {
        if (vowels.find(S[i]) == string::npos) continue;
        ans += solve(N);
        ans -= solve(i);
        ans -= solve(N - i - 1);
    }

    cout << setprecision(10) << fixed;
    cout << ans << '\n';
}