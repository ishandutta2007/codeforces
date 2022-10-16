#include <bits/stdc++.h>

using namespace std;

using Matrix = vector<vector<char>>;

Matrix Rotate90(const Matrix& m) {
    const int n = (int)m.size();
    Matrix res(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res[i][j] = m[n - 1 - j][i];
        }
    }
    return res;
}

Matrix Rotate180(const Matrix& m) {
    return Rotate90(Rotate90(m));
}

Matrix Rotate270(const Matrix& m) {
    return Rotate90(Rotate180(m));
}

Matrix FlipVertical(const Matrix& m) {
    const int n = (int)m.size();
    Matrix res(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res[i][j] = m[n - i - 1][j];
        }
    }
    return res;
}

Matrix FlipHorizontal(const Matrix& m) {
    return Rotate180(FlipVertical(Rotate180(m)));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
#endif
    int n; cin >> n;

    Matrix a(n, vector<char>(n)), b(n, vector<char>(n));
    for (auto& x : {&a, &b}) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> (*x)[i][j];
            }
        }
    }

    vector<Matrix(*)(const Matrix&)> funcs = {Rotate90, Rotate180, Rotate270};

    for (int i = 0; i <= 3; ++i) {
        Matrix x = (i == 3) ? b : funcs[i](b);
        for (int mask = 0; mask <= 3; ++mask) {
            if (mask & 1) {
                x = FlipVertical(x);
            }

            if (mask >> 1 & 1) {
                x = FlipHorizontal(x);
            }

            for (int j = 0; j <= 3; ++j) {
                Matrix y = (j == 3) ? x : funcs[j](x);
                if (y == a) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }

    cout << "No\n";

}