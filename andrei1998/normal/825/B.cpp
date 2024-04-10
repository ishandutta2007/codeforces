#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

string mat[10];

bool check() {
    for (int i = 0; i < 10; ++ i)
        for (int j = 0; j + 4 < 10; ++ j)
            if (mat[i][j] == 'X' &&
                mat[i][j + 1] == 'X' &&
                mat[i][j + 2] == 'X' &&
                mat[i][j + 3] == 'X' &&
                mat[i][j + 4] == 'X')
                return true;

    for (int i = 0; i + 4 < 10; ++ i)
        for (int j = 0; j < 10; ++ j)
            if (mat[i][j] == 'X' &&
                mat[i + 1][j] == 'X' &&
                mat[i + 2][j] == 'X' &&
                mat[i + 3][j] == 'X' &&
                mat[i + 4][j] == 'X')
                return true;

    for (int i = 0; i + 4 < 10; ++ i)
        for (int j = 0; j + 4 < 10; ++ j)
            if (mat[i][j] == 'X' &&
                mat[i + 1][j + 1] == 'X' &&
                mat[i + 2][j + 2] == 'X' &&
                mat[i + 3][j + 3] == 'X' &&
                mat[i + 4][j + 4] == 'X')
                return true;

    for (int i = 4; i < 10; ++ i)
        for (int j = 0; j + 4 < 10; ++ j)
            if (mat[i][j] == 'X' &&
                mat[i - 1][j + 1] == 'X' &&
                mat[i - 2][j + 2] == 'X' &&
                mat[i - 3][j + 3] == 'X' &&
                mat[i - 4][j + 4] == 'X')
                return true;


    return false;

}

int main()
{
    for (int i = 0; i < 10; ++ i)
        cin >> mat[i];

    for (int i = 0; i < 10; ++ i)
        for (int j = 0; j < 10; ++ j)
            if (mat[i][j] == '.') {
                mat[i][j] = 'X';
                if (check()) {
                    cout << "YES\n";
                    return 0;
                }
                mat[i][j] = '.';
            }

    cout << "NO\n";
    return 0;
}