#include <iostream>
#include <string>

using namespace std;

const int MAXN = 200 * 1000 + 5, K = 32;
unsigned int pc[1 << (K / 2)], a[K][(MAXN + K - 1) / K], b[K][(MAXN + K - 1) / K];
string sa, sb;

int popcount(unsigned int x) {
    return pc[x >> (K / 2)] + pc[x & ((1u << (K / 2)) - 1)];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < (1 << (K / 2)); i++)
        pc[i] = __builtin_popcount(i);
    cin >> sa >> sb;
    int n = sa.length(), m = sb.length();
    for(int i = 0; i < K; i++)
        for(int j = i; j < n; j++)
            if(sa[j] == '1')
                a[i][(j - i) / K] |= (1u << ((j - i) % K));
    for(int i = 0; i < K; i++)
        for(int j = i; j < m; j++)
            if(sb[j] == '1')
                b[i][(j - i) / K] |= (1u << ((j - i) % K));
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int p0, p1, len;
        cin >> p0 >> p1 >> len;
        int r0 = p0 % K, r1 = p1 % K, l0 = p0 / K, l1 = p1 / K,
            d = len / K, ans = 0;
        for(int i = 0; i < d; i++)
            ans += popcount(a[r0][l0++] ^ b[r1][l1++]);
        ans += popcount((a[r0][l0] ^ b[r1][l1]) & ((1u << (len % K)) - 1));
        cout << ans << '\n';
    }
    return 0;
}