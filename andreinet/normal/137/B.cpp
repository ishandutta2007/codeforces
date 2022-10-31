#include <iostream>
#include <cstdio>

using namespace std;

const int Nmax = 5005;

int Used[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios :: sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;

        Used[x] = 1;
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i)
        if (!Used[i])
            ++ans;

    cout << ans << '\n';
}