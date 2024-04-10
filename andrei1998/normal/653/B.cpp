#include <iostream>

using namespace std;

int n, q;

int ans;

char sir[105];
char aux[105];
char from[105][2];
char to[105];

void backtr(int pos) {
    if (pos == n + 1) {
        for (int i = 1; i <= n; ++ i)
            aux[i] = sir[i];

        aux[n + 1] = '\0';

        bool ok = true;
        for (int i = 1; i < n; ++ i) {
            int j;
           for (j = 1; j <= q; ++ j)
                if (aux[i] == from[j][0] && aux[i + 1] == from[j][1])
                    break;

            if (j == q + 1) {
                ok = false;
                break;
            }

            aux[i + 1] = to[j];
            ++ j;
        }

        ans += (ok && aux[n] == 'a');
        return ;
    }

    for (int i = 'a'; i <= 'f'; ++ i) {
        sir[pos] = i;
        backtr(pos + 1);
    }
}

int main()
{
    cin >> n >> q;

    for (int i = 1; i <= q; ++ i) {
        cin >> from[i][0] >> from[i][1] >> to[i];
    }

    backtr(1);
    cout << ans << '\n';
    return 0;
}