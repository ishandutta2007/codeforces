#include <iostream>

using namespace std;

const int MOD = 1000000000 + 7;
int pow(int a, int b) {
    int ans = 1, aux = a;
    while (b) {
        if (b & 1)
            ans = (1LL * ans * aux) % MOD;
        aux = (1LL * aux * aux) % MOD;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int cntBad = 0;
    for (int i = 1; i <= 3; ++ i)
        for (int j = 1; j <= 3; ++ j)
            for (int k = 1; k <= 3; ++ k)
                if (i + j + k == 6)
                    ++ cntBad;
    int N;
    cin >> N;

    int ans = pow(27, N) - pow(cntBad, N);
    if (ans < 0)
        ans += MOD;
    cout << ans << '\n';
    return 0;
}