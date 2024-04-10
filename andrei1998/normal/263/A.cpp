#include <bits/stdc++.h>

using namespace std;

int mat[5][5];

int main()
{
    int n = 5;

    int lin, col;
    for (int i = 0; i < 5; ++ i)
        for (int j = 0; j < 5; ++ j) {
            cin >> mat[i][j];
            if (mat[i][j] == 1)
                lin = i, col = j;
        }

    cout << abs(2 - lin) + abs(2 - col) << '\n';
    return 0;
}