#include <cstring>

#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;
const int MOD = 1000003;

int matrix[105][105];
int answer[105][105];
int w, aux[105][105];

void mult(int a[105][105], int b[105][105]) {
    memset(aux, 0, sizeof aux);
    for (int i = 0; i <= w; ++ i) {
        for (int j = 0; j <= w; ++ j) {
            for (int k = 0; k <= w; ++ k) {
                aux[i][j] = (1LL * aux[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    for (int i = 0; i <= w; i += 1) {
        for (int j = 0; j <= w; j += 1) {
            a[i][j] = aux[i][j];
        }
    }
}

int main() {
    int c, h;
    cin >> c >> w >> h;
    for (int i = 0; i <= w; i += 1) {
        matrix[i][0] = 1;
    }
    for (int i = 1; i <= w; i += 1) {
        matrix[i - 1][i] = h;
    }
    for (int i = 0; i <= w; i += 1) {
        answer[i][i] = 1;
    }
    for (; c; c >>= 1) {
        if (c & 1) {
            mult(answer, matrix);
        }
        mult(matrix, matrix);
    }
    // for (int i = 0; i <= w; ++ i) {
    //     for (int j = 0; j <= w; j += 1) {
    //         cout << answer[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    int sum = 0;
    for (int i = 0; i <= w; i += 1) {
        sum = (sum + answer[0][i]) % MOD;
    }
    cout << sum << "\n";
    return 0;
}