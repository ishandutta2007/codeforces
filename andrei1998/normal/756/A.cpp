#include <iostream>

using namespace std;

const int NMAX = 2 * 100000 + 5;

int N;
bool vis[NMAX];
int p[NMAX];
bool b[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> p[i];

    int ans = 0;
    for (int i = 1; i <= N; ++ i)
        cin >> b[i];

    int cnt = 0;
    for (int i = 1; i <= N; ++ i)
        if (b[i])
            ++ cnt;
    if (cnt % 2 == 0)
        ++ ans;

    int cntt = 0;
    for (int i = 1; i <= N; ++ i)
        if (!vis[i]) {
            int node = i;
            while (!vis[node]) {
                vis[node] = true;
                node = p[node];
            }
            ++ ans;
            ++ cntt;
        }

    if (cntt == 1)
        -- ans;
    cout << ans << '\n';
    return 0;
}