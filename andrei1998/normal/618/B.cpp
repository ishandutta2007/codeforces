#include <iostream>

using namespace std;

int mat[55][55];

int p[55];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            cin >> mat[i][j];

    for (int i = 1; i <= n; ++ i) {
        for (int who = 1; who <= n; ++ who)
            if (!p[who]) {
                int j;
                for (j = 1; j <= n; ++ j)
                    if (!p[j] && mat[who][j] != i && j != who)
                        break;

                if (j == n + 1) {
                    p[who] = i;
                    break;
                }
            }
    }

    for (int i = 1; i <= n; ++ i)
        if (p[i] == 0)
            p[i] = n;

    for (int i = 1; i <= n; ++ i)
        cout << p[i] << " \n"[i == n];
    return 0;
}