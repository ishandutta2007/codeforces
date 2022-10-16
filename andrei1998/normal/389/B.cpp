#include <iostream>
#include <string>

using namespace std;

const int NMAX = 100 + 5;

string mat[NMAX];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++ i) {
        cin >> mat[i];
        mat[i] = " " + mat[i] + " ";
    }

    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            if (mat[i][j] == '#') {
                if (mat[i + 1][j] == '#' && mat[i + 1][j - 1] == '#' && mat[i + 1][j + 1] == '#' && mat[i + 2][j] == '#') {
                    mat[i + 1][j] = '.';
                    mat[i + 1][j - 1] = '.';
                    mat[i + 1][j + 1] = '.';
                    mat[i + 2][j] = '.';
                }
                else {
                    cout << "NO\n";
                    return 0;
                }
            }

    cout << "YES\n";
    return 0;
}