#include <iostream>

using namespace std;

int f(int nr) {
    int prod = 1;
    while (nr) {
        int c = nr % 10;
        nr /= 10;
        if (c)
            prod *= c;
    }
    return prod;
}

int g(int nr) {
    if (nr < 10)
        return nr;
    else
        return g(f(nr));
}

int sPart[10][1000000 + 5];

int main()
{
    ios_base :: sync_with_stdio(false);
    for (int i = 0; i <= 1000000; ++ i) {
        sPart[g(i)][i] = 1;
        if (i > 0) {
            for (int j = 0; j < 10; ++ j)
                sPart[j][i] += sPart[j][i - 1];
        }
    }

    int Q;
    cin >> Q;

    while (Q --) {
        int l, r, k;
        cin >> l >> r >> k;
        -- l;
        cout << sPart[k][r] - sPart[k][l] << '\n';
    }

    return 0;
}