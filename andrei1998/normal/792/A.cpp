#include <bits/stdc++.h>

using namespace std;

const int NMAX = 2 * 100000 + 5;

int N;
int a[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> a[i];
    sort(a + 1, a + N + 1);

    int ans = a[2] - a[1];
    int cnt = 1;
    for (int i = 3; i <= N; ++ i) {
        if (a[i] - a[i - 1] < ans) {
            ans = a[i] - a[i - 1];
            cnt = 1;
        }
        else if (a[i] - a[i - 1] == ans)
            ++ cnt;
    }

    cout << ans << ' ' << cnt << '\n';
    return 0;
}