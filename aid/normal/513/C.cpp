#include <iostream>

using namespace std;

const int MAXN = 10, MAXX = 10 * 1000 + 5;
int l[MAXN], r[MAXN], n;
long double pr[MAXX];

long double getEq(int i, int x) {
    if(x < l[i] || x > r[i])
        return 0;
    return (long double)1 / (r[i] - l[i] + 1);
}

long double getGr(int i, int x) {
    if(x < l[i])
       return 1;
    if(x > r[i])
        return 0;
    return (long double)(r[i] - x) / (r[i] - l[i] + 1);
}

long double getPr(int x) {
    long double res = 0;
    for(int i = 0; i < n; i++) {
        long double s0 = 1, s1 = 1;
        for(int j = 0; j < n; j++)
            if(j != i) {
                s0 *= 1 - getGr(j, x);
                s1 *= 1 - getGr(j, x - 1);
            }
        res += (s0 - s1) * getGr(i, x);
    }
    for(int i = 0; i < (1 << n); i++) {
        if(__builtin_popcount(i) <= 1)
            continue;
        long double cur = 1;
        for(int j = 0; j < n; j++)
            if(i & (1 << j))
                cur *= getEq(j, x);
            else
                cur *= 1 - getGr(j, x - 1);
        res += cur;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(20);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    for(int i = 0; i < MAXX; i++)
        pr[i] = getPr(i);
    long double ans = 0;
    for(int i = 0; i < MAXX; i++)
        ans += i * pr[i];
    cout << ans << '\n';
    return 0;
}