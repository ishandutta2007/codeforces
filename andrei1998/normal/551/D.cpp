#include <iostream>
#include <cassert>

#define int long long int
using namespace std;

int m;
class matrix {
public:
    int mat[2][2];

    matrix () {
        mat[0][0] = mat[0][1] =
        mat[1][0] = mat[1][1] = 0;
    }

    matrix operator* (const matrix &b) const {
        matrix res;

        int j, k;
        for (int i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
                for (k = 0; k < 2; k++) {
                    res.mat[i][j] += (mat[i][k] * b.mat[k][j]) % m;

                    if (res.mat[i][j] >= m)
                        res.mat[i][j] -= m;
                }

        return res;
    }

    matrix operator^ (int b) const {
        matrix res;
        res.mat[0][0] = res.mat[1][1] = (1 % m);

        matrix aux = (*this);

        while (b) {
            if (b & 1)
                res = res * aux;

            b >>= 1;
            aux = aux * aux;
        }

        return res;
    }
} base, base_2;

void init_fibo () {
    base.mat[0][1] =
    base.mat[1][0] = base.mat[1][1] = (1 % m);

    base_2.mat[0][1] = base_2.mat[0][0] =
    base_2.mat[1][0] = base_2.mat[1][1] = (1 % m);
}

int fibo (int n) {
    n += 2;
    return ((base ^ n).mat[0][1]) % m;
}


int put_2 (int n) {
    n ++;
    return ((base_2 ^ n).mat[0][1]) % m;
}

int ans (int n) {
    return (put_2(n) - fibo(n) + m) % m;
}

signed main()
{
    ios_base :: sync_with_stdio(false);

    int n;
    int k;
    int l;

    cin >> n >> k >> l >> m;
    if (l <= 62 && (1ll << l) <= k) {
        cout << "0\n";
        return 0;
    }

    init_fibo();

    int anss = 1 % m;
    int i;
    for (i = 0; i < 62 && i < l; i++)
        if ((1ll << i) & k)
            anss = (anss * ans(n)) % m;
        else
            anss = (anss * fibo(n)) % m;

    for (; i < l; i++)
        anss = (anss * fibo(n)) % m;

    cout << anss << '\n';
    //assert(l < 64);

    return 0;
}