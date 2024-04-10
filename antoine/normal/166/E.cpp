#include <iostream>
#include <cstring>
#include <vector>

const int MOD = 1000000007;

typedef std::vector<std::vector<int64_t>> matrix;

matrix id;

matrix identity(int64_t n) {
    matrix v(n, std::vector<int64_t>(n, 0));
    for(int i = 0; i < n; ++i)
        v[i][i] = 1;
    return v;
}

matrix mul(matrix A, matrix B) {
    matrix R(4, std::vector<int64_t>(4, 0));
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            for(int k = 0; k < 4; ++k)
                R[i][j] = (R[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;
    return R;
}

matrix pow_matrix(matrix M, int64_t p) {
    if (p == 0) return id;
    if (p%2 == 0) return pow_matrix(mul(M, M), p/2);
    return mul(M, pow_matrix(M, p - 1));
}

int main() {
    id = identity(4);
    int64_t n;
    std::cin >> n;
    matrix M = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}
    };
    M = pow_matrix(M, n);
    std::cout << M[3][3];
}