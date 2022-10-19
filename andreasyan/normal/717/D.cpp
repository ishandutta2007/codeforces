#include <bits/stdc++.h>
using namespace std;
//#define double int
const int N = 130;
struct ban
{
    int n, m;
    double a[N][N];
    ban(){};
    ban(int n, int m)
    {
        this->n = n;
        this->m = m;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                a[i][j] = 0.0;
            }
        }
    }
};
ban operator*(const ban& t1, const ban& t2)
{
    assert(t1.m == t2.n);
    ban t(t1.n, t2.m);
    for (int i = 0; i < t.n; ++i)
    {
        for (int j = 0; j < t.m; ++j)
        {
            for (int k = 0; k < t1.m; ++k)
                t.a[i][j] += t1.a[i][k] * t2.a[k][j];
        }
    }
    return t;
}
ban zro(int n)
{
    ban t(n, n);
    for (int i = 0; i < n; ++i)
        t.a[i][i] = 1.0;
    return t;
}

int n, m, k;

ban ast(ban x, int n)
{
    if (n == 0)
        return zro(k);
    if (n % 2 == 0)
    {
        ban y = ast(x, n / 2);
        return y * y;
    }
    else
    {
        ban y = ast(x, n - 1);
        return x * y;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(8);
    cin >> n >> m;
    k = 1;
    while (k <= m)
        k *= 2;
    ban s(1, k);
    for (int j = 0; j <= m; ++j)
        cin >> s.a[0][j];
    ban t(k, k);
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            t.a[i][(i ^ j)] += s.a[0][j];
        }
    }
    /*for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
            cout << t.a[i][j] << ' ';
        cout << endl;
    }*/
    ban y = ast(t, n - 1);
    ban ans = s * y;
    double yans = 0;
    for (int j = 1; j < k; ++j)
        yans += ans.a[0][j];
    cout << yans << endl;
    return 0;
}