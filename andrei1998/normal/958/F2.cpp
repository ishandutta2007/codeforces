#include <bits/stdc++.h>

using namespace std;

const int NMAX = 200000 + 5;

int N, M;
int v[NMAX];
int requirement[NMAX];

int main() {
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 1; i <= N; ++ i)
        cin >> v[i];

    int sm = 0;
    for (int i = 1; i <= M; ++ i) {
        cin >> requirement[i];
        sm += requirement[i];
    }

    int j = 0;
    for (int type = 1; type <= M; ++ type)
        while (requirement[type] > 0) {
            ++ j;
            if (j == N + 1) {
                cout << "-1\n";
                //cout << "NO\n";
                return 0;
            }
            -- requirement[v[j]];
        }

    int ans = j - sm;
    for (int i = 2; i <= N; ++ i) {
        ++ requirement[v[i - 1]];
        while (requirement[v[i - 1]] > 0) {
            ++ j;
            if (j == N + 1)
                goto done;
            -- requirement[v[j]];
        }
        ans = min(ans, j - i + 1 - sm);
    }

    done:
    if (ans == N + 1)
        cout << "-1\n";
    else
        cout << ans << '\n';
    return 0;
}