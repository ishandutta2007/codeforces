#include <iostream>

using namespace std;

int N, K;
bool mat[105][105];

int main()
{
    cin >> N >> K;

    for (int i = 1; i <= N && K; ++ i)
        for (int j = i; j <= N && K; ++ j)
            if (i == j) {
                mat[i][i] = 1;
                -- K;
            }
            else {
                if (K >= 2) {
                    mat[i][j] = mat[j][i] = 1;
                    K -= 2;
                }
                else {
                    if (i < N) {
                        mat[i + 1][i + 1] = 1;
                        K = 0;
                    }
                }
            }

    if (K > 0) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= N; ++ j)
            cout << mat[i][j] << " \n"[j == N];
    return 0;
}