#include <iostream>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;

const int NMAX = 55;

int n;
char mat[NMAX][NMAX];
char mat2[NMAX][NMAX];

bool works(int lin1, int col1, int lin2, int col2) {
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            mat2[i][j] = '0';

    //Build mat2
    for (int i = lin1; i <= lin2; ++ i)
        for (int j = col1; j <= col2; ++ j)
            mat2[i][j] = '4';

    for (int i = lin1; i <= lin2; ++ i) {
        mat2[i][col1 - 1] = '2';
        mat2[i][col2 + 1] = '2';
    }

    for (int j = col1; j <= col2; ++ j) {
        mat2[lin1 - 1][j] = '2';
        mat2[lin2 + 1][j] = '2';
    }

    mat2[lin1 - 1][col1 - 1] = '1';
    mat2[lin1 - 1][col2 + 1] = '1';
    mat2[lin2 + 1][col1 - 1] = '1';
    mat2[lin2 + 1][col2 + 1] = '1';

    //Compare
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            if (mat[i][j] != mat2[i][j])
                return false;
    return true;
}

bool get_sol() {
    int minlin = NMAX;
    int maxlin = 0;
    int mincol = NMAX;
    int maxcol = 0;

    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            if (mat[i][j] == '4') {
                minlin = min(minlin, i);
                maxlin = max(maxlin, i);

                mincol = min(mincol, j);
                maxcol = max(maxcol, j);
            }

    if (maxlin < minlin)
        return false;
    return works(minlin, mincol, maxlin, maxcol);
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; ++ i) {
        cin.get(); cin.get(mat[i] + 1, NMAX);
    }

    if (get_sol())
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}