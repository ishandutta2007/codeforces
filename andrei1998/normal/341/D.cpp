#include <iostream>

using namespace std;

const int NMAX = 1000 + 5;

inline int lsb(int node) {
    return node & (-node);
}

typedef long long int lint;

int N;
lint aib[2][2][NMAX][NMAX];

void update(int lin, int col, lint val) {
    for (int i = lin; i <= N; i += lsb(i))
        for (int j = col; j <= N; j += lsb(j))
            aib[lin & 1][col & 1][i][j] ^= val;
}

lint query(int lin, int col) {
    lint ans = 0;
    for (int i = lin; i; i -= lsb(i))
        for (int j = col; j; j -= lsb(j))
            ans ^= aib[lin & 1][col & 1][i][j];
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int M = 0;
    cin >> N >> M;

    for (int i = 1; i <= M; ++ i) {
        int type, lin1, col1, lin2, col2;
        cin >> type >> lin1 >> col1 >> lin2 >> col2;

        if (type == 1) {
            cout << (query(lin2, col2) ^
                     query(lin2, col1 - 1) ^
                     query(lin1 - 1, col2) ^
                     query(lin1 - 1, col1 - 1)) << '\n';
        }
        else {
            lint val;
            cin >> val;

            update(lin1, col1, val);
            update(lin1, col2 + 1, val);
            update(lin2 + 1, col1, val);
            update(lin2 + 1, col2 + 1, val);
        }
    }

    return 0;
}