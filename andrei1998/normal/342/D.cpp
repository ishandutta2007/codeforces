#include <iostream>
#include <string>

using namespace std;

const int MOD = 1000000000 + 7;
const int NMAX = 10000 + 5;

int N;
string mat[3];

int dp[NMAX][4][1 << 3][2];

void upd(int &where, int val) {
    where += val;
    if (where >= MOD)
        where -= MOD;
}

int setBit(int mask, int bit, int val) {
    mask &= (7 - (1 << bit));
    if (val)
        mask |= (1 << bit);
    return mask;
}

int main()
{
    cin >> N;

    for (int i = 0; i < 3; ++ i) {
        cin >> mat[i];
        mat[i] = " " + mat[i] + "X";
    }

    int OLin, OCol;
    for (int i = 0; i < 3; ++ i)
        for (int j = 1; j <= N; ++ j)
            if (mat[i][j] == 'O') {
                mat[i][j] = 'X';
                OLin = i;
                OCol = j;
                goto done;
            }
    done:

    int msk = 0;
    for (int i = 0; i < 3; ++ i)
        if (mat[i][1] == 'X')
            msk |= (1 << i);
    dp[1][0][msk][0] = 1;

    for (int col = 1; col <= N; ++ col) {
        for (int lin = 0; lin < 3; ++ lin)
            for (int mask = 0; mask < (1 << 3); ++ mask) {
                if (mask & (1 << lin)) { //Current cell is blocked
                    upd(dp[col][lin + 1][setBit(mask, lin,  mat[lin][col + 1] == 'X')][0], dp[col][lin][mask][0]);
                    upd(dp[col][lin + 1][setBit(mask, lin,  mat[lin][col + 1] == 'X')][1], dp[col][lin][mask][1]);
                }
                else {
                    //Place right
                    if (col + 1 <= N && mat[lin][col + 1] == '.') {
                        upd(dp[col][lin + 1][mask | (1 << lin)][1], dp[col][lin][mask][1]);
                        upd(dp[col][lin + 1][mask | (1 << lin)][lin == OLin && (col - 1 == OCol || col + 2 == OCol)], dp[col][lin][mask][0]);
                    }

                    //Place down
                    if (lin + 1 < 3 && !(mask & (1 << (lin + 1)))) {
                        upd(dp[col][lin + 1][setBit(setBit(mask, lin, mat[lin][col + 1] == 'X'), lin + 1, 1)][1], dp[col][lin][mask][1]);
                        upd(dp[col][lin + 1][setBit(setBit(mask, lin, mat[lin][col + 1] == 'X'), lin + 1, 1)][col == OCol && (lin - 1 == OLin || lin + 2 == OLin)], dp[col][lin][mask][0]);
                    }
                }
            }

        for (int mask = 0; mask < (1 << 3); ++ mask) {
            upd(dp[col + 1][0][mask][0], dp[col][3][mask][0]);
            upd(dp[col + 1][0][mask][1], dp[col][3][mask][1]);
        }
    }

    cout << dp[N + 1][0][7][1] << '\n';
    return 0;
}