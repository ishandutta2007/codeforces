#include <iostream>
using namespace std;
const long long N = 100005;
const long long M = 100000000011;

long long x1, x2;
long long y1, y2;

long long n;
char a[N];
long long x[N];
long long y[N];

long long abss(long long x)
{
    if (x < 0)
        return -x;
    return x;
}

bool stg(long long m)
{
    if (m == 2)
        cout << "";
    long long xx = x1, yy = y1;
    xx += (x[n] * (m / n) + x[m % n]);
    yy += (y[n] * (m / n) + y[m % n]);
    return (abss(xx - x2) + abss(yy - y2) <= m);
}

long long byn()
{
    long long l = 1, r = M * N;
    while ((r - l) > 4)
    {
        long long m = (l + r) / 2;
        if (stg(m))
            r = m;
        else
            l = m;
    }
    for (long long m = l; m <= r; ++m)
        if (stg(m))
            return m;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        x[i] = x[i - 1];
        y[i] = y[i - 1];
        if (a[i] == 'U')
            y[i]++;
        if (a[i] == 'D')
            y[i]--;
        if (a[i] == 'L')
            x[i]--;
        if (a[i] == 'R')
            x[i]++;
    }
    cout << byn() << endl;
    return 0;
}