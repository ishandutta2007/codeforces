#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1E5 + 10;

int N, K;
int v[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> N >> K;
    for (int i = 1; i <= N; ++ i)
        cin >> v[i];
    sort(v + 1, v + N + 1);

    long long int ans = 0;
    for (int i = 2; i <= N; ++ i)
        if (v[i] % K != v[1] % K) {
            cout << "-1\n";
            return 0;
        }
        else
            ans += (v[i] - v[1]) / K;
    cout << ans << '\n';
    return 0;
}