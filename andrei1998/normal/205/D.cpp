#include <iostream>
#include <map>

using namespace std;

const int NMAX = 1e5 + 5;
int n;
int a[NMAX];
int b[NMAX];

map <int, int> Map;

int doTry(int val) {
    int cnt = 0;
    for (int i = 1; i <= n; ++ i)
        if (a[i] == val)
            ++ cnt;

    if (cnt >= (n + 1) / 2)
        return 0;

    int ans = 0;
    for (int i = 1; i <= n && cnt < (n + 1) / 2; ++ i)
        if (a[i] != val && b[i] == val) {
            ++ cnt;
            ++ ans;
        }

    if (cnt < (n + 1) / 2)
        return NMAX;
    else
        return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; ++ i) {
        cin >> a[i] >> b[i];
        ++ Map[a[i]];
        ++ Map[b[i]];
    }

    int ans = NMAX;
    for (auto it: Map)
        if (it.second >= (n + 1) / 2)
            ans = min(ans, doTry(it.first));

    if (ans == NMAX)
        cout << "-1\n";
    else
        cout << ans << '\n';
    return 0;
}