#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)1e9 + 7;
const int maxN = (int)1e6 + 5;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sum2[maxN], sum1[maxN], sum0[maxN];
int dig[6][maxN];
int n;
int pw[6];
int val[maxN];
int pw2[maxN + 5];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    pw[0] = 1;
    for (int i = 1; i < 6; i++) pw[i] = 10 * pw[i - 1];
    pw2[0] = 1;
    for (int i = 1; i <= maxN; i++) pw2[i] = mult(pw2[i - 1], 2);
    //freopen("input.txt", "r", stdin);
    for (int i = 0; i < maxN; i++) {
        int c = i;
        for (int j = 0; j < 6; j++) {
            dig[j][i] = c % 10;
            c /= 10;
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum2[x] = sum(sum2[x], mult(x, x));
        sum1[x] = sum(sum1[x], x);
        sum0[x] = sum(sum0[x], 1);
    }
    for (int bit = 0; bit < 6; bit++) {
        for (int i = 0; i < maxN; i++) {
            int c = dig[bit][i];
            for (int k = 0; k < c; k++) {
                int num = i - (c - k) * pw[bit];
                sum2[num] = sum(sum2[num], sum2[i]);
                sum1[num] = sum(sum1[num], sum1[i]);
                sum0[num] = sum(sum0[num], sum0[i]);
            }
        }
    }
    for (int i = 0; i < maxN; i++) {
        if (sum0[i] == 0) continue;
        if (sum0[i] == 1) {
            val[i] = sum2[i];
            continue;
        }
        val[i] = mult(pw2[sum0[i] - 2], sum(sum2[i], mult(sum1[i], sum1[i])));
    }
    for (int bit = 0; bit < 6; bit++) {
        for (int i = 0; i < maxN; i++) {
            int c = dig[bit][i];
            if (c >= 1) {
                int num = i - pw[bit];
               // cout << num << " " << i << " " << bit << " here" << endl;
                val[num] = sub(val[num], val[i]);
            }
            /*for (int k = 0; k < c; k++) {
                int num = i - (c - k) * pw[bit];
                val[num] = sub(val[num], val[i]);
            }*/
        }
    }
    ll ans = 0;
    for (int i = 0; i < maxN; i++) {
        ans ^= (1LL * val[i] * i);
    }
    cout << ans;
}