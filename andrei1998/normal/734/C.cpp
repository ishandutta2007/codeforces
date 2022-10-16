#include <iostream>
#include <algorithm>
#include <utility>

#define lint long long int
using namespace std;

const int NMAX = 400000 + 5;

int n, m, k;
int x, s;

int a[NMAX];
int b[NMAX];

int c[NMAX];
int d[NMAX];

int best2(int mana) {
    int ans = 0;
    int st = 1;
    int dr = k;
    int mid;

    while (st <= dr) {
        mid = (st + dr) >> 1;

        if (d[mid] <= mana) {
            ans = mid;
            st = mid + 1;
        }
        else
            dr = mid - 1;
    }

    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n >> m >> k;
    cin >> x >> s;

    a[0] = x;
    for (int i = 1; i <= m; ++ i)
        cin >> a[i];
    for (int i = 1; i <= m; ++ i)
        cin >> b[i];

    for (int i = 1; i <= k; ++ i)
        cin >> c[i];
    for (int i = 1; i <= k; ++ i)
        cin >> d[i];

    lint ans = 1LL * n * x;
    for (int i = 0; i <= m; ++ i) {
        int mana = s - b[i];
        if (mana < 0)
            continue;

        int secs = a[i];

        int who = best2(mana);

        lint aux = 1LL * (n - c[who]) * secs;
        ans = min(ans, aux);
    }

    cout << ans << '\n';
    return 0;
}