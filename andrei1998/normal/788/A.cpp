#include <iostream>
#include <cstdlib>

using namespace std;

typedef long long int lint;

const int NMAX = 100000 + 5;

int N;
int a[NMAX];
lint sPart[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> a[i];
    for (int i = 1; i <= N; ++ i)
        a[i] = abs(a[i] - a[i + 1]);
    -- N;

    for (int i = N; i; -- i)
        sPart[i] = a[i] - sPart[i + 1];

    lint maxim[2];
    for (int i = 0; i < 2; ++ i)
        maxim[i] = -(1E18 + 15);
    maxim[(N + 1) & 1] = 0;

    lint ans = 0;
    for (int i = N; i; -- i) {
        ans = max(ans, sPart[i] + maxim[(i & 1) ^ 1]);
        maxim[i & 1] = max(maxim[i & 1], sPart[i]);
    }

    cout << ans << '\n';
    return 0;
}