#include <bits/stdc++.h>

using namespace std;

const int NMAX = 2E5 + 15;

int N, K;
int v[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; ++ i)
        cin >> v[i];

    long long int all = 0;
    long long int sum = 0;
    for (int i = 1; i <= K; ++ i)
        sum += v[i];

    all = sum;
    for (int i = K + 1; i <= N; ++ i) {
        sum += v[i];
        sum -= v[i - K];
        all += sum;
    }

    long double ans = all / (N - K + 1.0L);
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}