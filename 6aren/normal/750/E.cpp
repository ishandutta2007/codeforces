#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 200005;
const int oo = 1000000000;

struct Matrix {
    int a[5][5];
    
    Matrix(int init = -1) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) 
                a[i][j] = oo;
            a[i][i] = 0;
        }

        if (init == 2) {
            a[0][0] = 1;
            a[0][1] = 0;
        } else if (init == 0) {
            a[1][1] = 1;
            a[1][2] = 0;
        } else if (init == 1) {
            a[2][2] = 1;
            a[2][3] = 0;
        } else if (init == 7) {
            a[3][3] = 1;
            a[3][4] = 0;
        } else if (init == 6) {
            a[3][3] = 1;
            a[4][4] = 1;
        }
    }

    Matrix operator * (const Matrix o) const {
        int res[5][5];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                res[i][j] = oo;
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    res[i][j] = min(res[i][j], this->a[i][k] + o.a[k][j]);
                }
            }
        }
        Matrix ans;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) ans.a[i][j] = res[i][j];
        }
        return ans;
    }
} it[4 * N];

int n, q;
string s;

void build(int k, int l, int r) {
    if (l == r) {
        int c = s[l] - '0';
        it[k] = Matrix(c);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    it[k] = it[2 * k] * it[2 * k + 1];
}

Matrix get(int k, int l, int r, int u, int v) {
    if (l > v || r < u) return Matrix();
    if (l >= u && r <= v) return it[k];
    int mid = (l + r) / 2;
    Matrix g1 = get(2 * k, l, mid, u, v);
    Matrix g2 = get(2 * k + 1, mid + 1, r, u, v);
    return g1 * g2;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n >> q;
    cin >> s;
    s = " " + s;
    build(1, 1, n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        Matrix res = get(1, 1, n, l, r);
        cout << (res.a[0][4] == oo ? -1 : res.a[0][4]) << '\n';
    }
    return 0;
}