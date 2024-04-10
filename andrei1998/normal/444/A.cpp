#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

const int NMAX = 500 + 5;

int N, M;
int v[NMAX];

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; ++ i)
        cin >> v[i];

    long double ans = 0;
    while (M --) {
        int a, b, c;
        cin >> a >> b >> c;
        ans = max(ans, 1.0L * (v[a] + v[b]) / c);
    }
    cout << fixed << setprecision(15) << ans << '\n';
    return 0;
}