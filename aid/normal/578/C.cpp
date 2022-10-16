#include <iostream>

using namespace std;

const int MAXN = 200 * 1000 + 5, MAXX = 10 * 1000 + 5;
int a[MAXN];
long double aa[MAXN];

long double get(int n) {
    long double res = 0, sum = 0;
    for(int i = 0; i < n; i++) {
        sum += aa[i];
        if(res < sum)
            res = sum;
        if(sum < 0)
            sum = 0;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(10);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    long double l = -MAXX, r = MAXX;
    for(int it = 0; it < 100; it++) {
        long double m = (l + r) / 2;
        for(int i = 0; i < n; i++)
            aa[i] = a[i] - m;
        long double pos = get(n);
        for(int i = 0; i < n; i++)
            aa[i] *= -1;
        long double neg = get(n);
        if(pos > neg)
            l = m;
        else
            r = m;
    }
    for(int i = 0; i < n; i++)
        aa[i] = a[i] - l;
    cout << get(n) << '\n';
    return 0;
}