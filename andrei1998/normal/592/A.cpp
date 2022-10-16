#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char mat[15][15];

bool works_white (int lin, int col) {
    for (int i = lin; i >= 1; -- i)
        if (mat[i][col] == 'B')
            return false;
    return true;
}

bool works_black (int lin, int col) {
    for (int i = lin; i <= 8; ++ i)
        if (mat[i][col] == 'W')
            return false;
    return true;
}

int main()
{
    for (int i = 1; i <= 8; ++ i) {
        cin.get(mat[i] + 1, 15);
        cin.get();
    }

    int best_white = 10;
    int best_black = 10;

    for (int i = 1; i <= 8; ++ i)
        for (int j = 1; j <= 8; ++ j)
            if (mat[i][j] == 'W' && works_white(i, j))
                best_white = min(best_white, i - 1);
            else if (mat[i][j] == 'B' && works_black(i, j))
                best_black = min(best_black, 8 - i);

    if (best_black < best_white)
        cout << "B\n";
    else
        cout << "A\n";
    return 0;
}