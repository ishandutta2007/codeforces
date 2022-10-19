#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const long long M = 1000003;
struct ban
{
    long long x;
    ban()
    {
        x = 0;
    }
    ban(long long x)
    {
        this->x = x % M;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.x < b.x;
}
bool operator>(const ban& a, const ban& b)
{
    return a.x > b.x;
}
bool operator==(const ban& a, const ban& b)
{
    return a.x == b.x;
}
ban operator+(const ban& a, const ban& b)
{
    return ban(a.x + b.x);
}
ban operator*(const ban& a, const ban& b)
{
    return ban(a.x * b.x);
}
ban ast(ban x, int n)
{
    if (n == 0)
        return ban(1);
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
ban operator/(const ban& a, const ban& b)
{
    return a * ast(b, M - 2);
}
ban operator-(const ban& a, const ban& b)
{
    return ban(a.x - b.x + M);
}

const int n = 50;
const int m = 10;
ban a[N][N];
ban b[N];

int w[N];
ban g[N];
int solv()
{
    for (int ii = 1; ii <= n; ++ii)
    {
        cout << "? " << ii << endl;
        cin >> b[ii].x;
        //b[ii] = ban(M - 7) + ban(ii);
        //b[ii] = ban(ii);
        for (int j = 0; j <= m; ++j)
            a[ii][j] = ast(ban(ii), j);
    }
    for (int jj = 0, ii = 1; jj <= m && ii <= n; ++jj)
    {
        ban maxu;
        int maxi;
        for (int i = ii; i <= n; ++i)
        {
            if (a[i][jj] > maxu)
            {
                maxu = a[i][jj];
                maxi = i;
            }
        }
        w[jj] = ii;
        for (int j = 0; j <= m; ++j)
        {
            swap(a[ii][j], a[maxi][j]);
        }
        swap(b[ii], b[maxi]);
        for (int i = 1; i <= n; ++i)
        {
            if (i == ii)
                continue;
            ban t = a[i][jj] / a[ii][jj];
            for (int j = jj; j <= m; ++j)
            {
                a[i][j] = a[i][j] - a[ii][j] * t;
            }
            b[i] = b[i] - b[ii] * t;
        }

        ++ii;
    }
    /*for (int ii = 1; ii <= m + 1; ++ii)
    {
        for (int jj = 0; jj <= m; ++jj)
        {
            cout << a[ii][jj].x << ' ';
        }
        cout << b[ii].x << endl;
    }*/

    for (int jj = 0; jj <= m; ++jj)
    {
        int ii = w[jj];
        if (ii == 0)
            continue;
        g[jj] = b[ii] / a[ii][jj];
    }
    /*for (int jj = 0; jj <= m; ++jj)
    {
        cout << g[jj].x << ' ';
    }
    cout << endl;*/

    for (int x = 0; x < M; ++x)
    {
        ban u;
        for (int j = 0; j <= m; ++j)
        {
            u = u + g[j] * ast(ban(x), j);
        }
        if (u.x == 0)
            return x;
    }
    return -1;
}

int main()
{
    int x = solv();
    cout << "! " << x << endl;
    return 0;
}