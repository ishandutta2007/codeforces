#include <iostream>
#include <algorithm>

using namespace std;

int d[100005];
int h[100005];

int gt (int h1, int h2, int n) {
    if (h2 < h1)
        swap(h1, h2);

    if (h2 - h1 > n - 1)
        return -1;

    n -= (h2 - h1);

    return h2 + (n - 1) / 2;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0, m = 0;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
        cin >> d[i] >> h[i];

    int ans = max(h[1] + d[1] - 1, h[m] + n - d[m]);
    bool ok = true;

    int aux = 0;
    for (int i = 1; i < m; i++) {
        aux = gt(h[i], h[i + 1], d[i + 1] - d[i] + 1);

        if (aux < 0) {
            ok = false;
            break;
        }
        else if (aux > ans)
            ans = aux;
    }

    if (ok)
        cout << ans << '\n';
    else
        cout << "IMPOSSIBLE\n";

    return 0;
}