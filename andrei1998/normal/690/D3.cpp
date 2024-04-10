#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MOD = 1000003;

int c, w, h;

class matrix {
public:
    int val[105][105];

    matrix () {
        memset(val, 0, sizeof(val));
    }

    matrix operator* (const matrix &b) const {
        matrix ans;

        int j, k;
        for (int i = 1; i <= w + 1; i++)
            for (j = 1; j <= w + 1; j++)
                for (k = 1; k <= w + 1; k++)
                    ans.val[i][j] = (ans.val[i][j] + 1LL * val[i][k] * b.val[k][j]) % MOD;
        return ans;
    }

    matrix I10 () {
        matrix ans;
        for (int i = 1; i <= w + 1; i++)
            ans.val[i][i] = 1;

        return ans;
    }

    matrix operator^ (int b) {
        matrix ans = I10();
        matrix aux = (*this);

        while (b) {
            if (b & 1)
                ans = ans * aux;

            b >>= 1;
            aux = aux * aux;
        }

        return ans;
    }
} v;

int main()
{
    cin >> c >> w >> h;

    for (int i = 1; i <= w + 1; ++ i) {
        v.val[i][1] = 1;
        if (i <= w)
            v.val[i][i + 1] = h;
    }

    v = v ^ c;

    int ans = 0;
    for (int i = 1; i <= w + 1; ++ i) {
        ans += v.val[1][i];
        if (ans >= MOD)
            ans -= MOD;
    }

    cout << ans << '\n';
    return 0;
}