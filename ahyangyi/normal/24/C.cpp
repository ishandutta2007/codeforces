#include <iostream>
#include <complex>

using namespace std;

int n;
long long j;
complex<long long> m0;
complex<long long> a[100000];
complex<long long> s[200001];

void get (complex<long long>& x)
{
    int a, b;

    cin >> a >> b;
    x = complex<long long>(a,b);
}

int main ()
{
    cin >> n >> j;
    get(m0);

    for (int i = 0; i < n; i ++)
    {
        get(a[i]);
        a[i] *= 2;
    }
    s[0] = 0;
    for (int i = 0; i < n + n; i ++)
        s[i + 1] = a[i % n] - s[i];
    m0 += s[n + n] * (j / (2 * n));
    j -= j / (2 * n) * (2 * n);
    if (j % 2 == 1)
    {
        m0 = s[j] - m0;
    }
    else
    {
        m0 = s[j] + m0;
    }

    cout << m0.real() << " " << m0.imag() << endl;

    return 0;
}