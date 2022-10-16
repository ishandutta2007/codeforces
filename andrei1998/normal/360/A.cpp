#include <iostream>

using namespace std;

const int NMAX = 5000 + 5;

int type[NMAX];
int l[NMAX];
int r[NMAX];
int v[NMAX];

int addent[NMAX];
int atMost[NMAX];

//Test
int a[NMAX];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++ i)
        atMost[i] = 1000000000;

    for (int i = 1; i <= m; ++ i) {
        cin >> type[i] >> l[i] >> r[i] >> v[i];

        if (type[i] == 1) {
            for (int j = l[i]; j <= r[i]; ++ j)
                addent[j] += v[i];
        }
        else {
            for (int j = l[i]; j <= r[i]; ++ j)
                atMost[j] = min(atMost[j], v[i] - addent[j]);
        }
    }

    for (int i = 1; i <= n; ++ i)
        a[i] = atMost[i];

    for (int i = 1; i <= m; ++ i) {
        if (type[i] == 1) {
            for (int j = l[i]; j <= r[i]; ++ j)
                a[j] += v[i];
        }
        else {
            int maximum = -1000000005;

            for (int j = l[i]; j <= r[i]; ++ j)
                maximum = max(maximum, a[j]);

            if (maximum != v[i]) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= n; ++ i)
        cout << atMost[i] << " \n"[i == n];
    return 0;
}