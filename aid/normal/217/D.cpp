#include <iostream>
#include <bitset>

using namespace std;

const int MAXM = 125, MAXK = 6, MOD = 1000 * 1000 * 1000 + 7;
int cnt[(MAXM + 1) / 2];

int gen(int pos, int k, int m, int x, bitset<MAXM> &bs) {
    if(k == MAXK)
        return x;
    int res = x;
    for(int i = pos; i <= m - i; i++) {
        if(!cnt[i] || bs[i])
            continue;
        bitset<MAXM> tobs = bs | (bs << i) | (bs >> (m - i)) |
            (bs << (m - i)) | (bs >> i);
        res = (res + gen(i + 1, k + 1, m,
                         (long long)x * cnt[i] % MOD, tobs)) % MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, t;
    cin >> n >> m >> t;
    for(int i = 0; i < t; i++) {
        int a;
        cin >> a;
        a %= m;
        if(a > m - a)
            a = m - a;
        cnt[a]++;
    }
    bitset<MAXM> bs;
    bs[0] = 1;
    cout << gen(0, 0, m, 1, bs) << '\n';
    return 0;
}