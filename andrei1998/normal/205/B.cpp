#include <iostream>

#define lint long long int
using namespace std;

const int NMAX = 1e5 + 5;

int N;
int a[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> a[i];

    lint ans = 0;
    for (int i = N - 1; i; -- i)
        if (a[i] > a[i + 1])
            ans += a[i] - a[i + 1];

    cout << ans << '\n';
    return 0;
}