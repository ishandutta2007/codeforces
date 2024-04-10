#include <iostream>

using namespace std;

const int NMAX = 1000 + 5;

int n;
char mat[NMAX][NMAX];

void add_edge(int a, int b) {
    mat[a][b] = mat[b][a] = 'Y';
}

int main()
{
    for (int i = 0; i < NMAX; ++ i)
        for (int j = 0; j < NMAX; ++ j)
            mat[i][j] = 'N';


    int k = 0;
    cin >> k;

    n = 3;
    for (int i = 0; i <= 30; ++ i) {
        if (i > 0) {
            add_edge(n, n - 2);
            add_edge(n, n - 1);
            add_edge(n + 1, n - 2);
            add_edge(n + 1, n - 1);
        }
        n += 2;
    }

    -- n;
    add_edge(n - 1, 2);
    add_edge(n, 2);

    for (int i = 0; i <= 30; ++ i) {
        ++ n;
        if (!i)
            add_edge(1, n);
        else
            add_edge(n - 1, n);

        if (k & (1 << (30 - i)))
            add_edge(n, (n - 65) * 2 + 3);
    }

    cout << n << '\n';
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j)
            cout << mat[i][j];
        cout << '\n';
    }
    return 0;
}