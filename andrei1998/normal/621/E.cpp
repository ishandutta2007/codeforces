#include <iostream>
#include <vector>

using namespace std;

int mod;
int putere(int a, int b) {
    if (!b)
        return (1 % mod);
    else if (b & 1)
        return (a * putere(a, b - 1)) % mod;
    else {
        int aux = putere(a, b >> 1);
        return (aux * aux) % mod;
    }
}


const int big_mod = 1000000007;

void unite(vector <int> &res, vector <int> a, vector <int> b, int factor) {
    res.clear();
    res.resize(mod, 0);

    int where;
    for (int i = 0; i < mod; ++ i)
        for (int j = 0; j < mod; ++ j) {
            where = (i * factor + j) % mod;
            res[where] = (res[where] + 1ll * a[i] * b[j]) % big_mod;
        }
}

vector <int> precalcs[34];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, b, k;
    cin >> n >> b >> k >> mod;

    precalcs[0].resize(mod, 0);

    int val;
    for (int i = 0; i < n; ++ i) {
        cin >> val;
        ++ precalcs[0][val % mod];
    }

    int current_l = 1;
    for (int i = 1; i < 31; ++ i, current_l *= 2)
        unite(precalcs[i], precalcs[i - 1], precalcs[i - 1], putere(10, current_l));

    vector <int> ans(mod, 0);
    ans[0] = 1;

    for (int i = 0; i < 31; ++ i)
        if (b & (1 << i))
            unite(ans, ans, precalcs[i], putere(10, 1 << i));

    cout << ans[k] << '\n';
    return 0;
}