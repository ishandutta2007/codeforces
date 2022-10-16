#include <iostream>
#include <cstring>

using namespace std;

const int NMAX = 100000 + 5;

int n, m;
int exam[NMAX];

int prep[NMAX];

int where[NMAX];

bool works(int b) {
    memset(where, 0, sizeof where);

    for (int i = b; i >= 1; -- i)
        if (!where[exam[i]] && exam[i])
            where[exam[i]] = i;

    int free_days = 0;
    int given = 0;
    for (int i = 1; i <= b; ++ i)
        if (i == where[exam[i]]) {
            ++ given;
            if (free_days >= prep[exam[i]])
                free_days -= prep[exam[i]];
            else
                return false;
        }
        else
            ++ free_days;

    return given == m;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
        cin >> exam[i];
    for (int i = 1; i <= m; ++ i)
        cin >> prep[i];

    int st = 1, dr = n, ans = n + 1, mid;
    while (st <= dr) {
        mid = (st + dr) >> 1;
        if (works(mid)) {
            ans = mid;
            dr = mid - 1;
        }
        else
            st = mid + 1;
    }

    if (ans == n + 1)
        cout << "-1\n";
    else
        cout << ans << '\n';

    return 0;
}