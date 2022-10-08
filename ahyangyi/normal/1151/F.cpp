#include <iostream>
#include <vector>

using namespace std;

const int MODULO = 1000000007;

int gcd(int a, int b, int& ax, int& bx)
{
    if (b == 0)
    {
        ax = 1;
        bx = 0;
        return b;
    }

    int g = gcd(b, a % b, bx, ax);
    bx = (bx - (long long)(a / b) * ax % MODULO + MODULO) % MODULO;
    return g;
}

int inv(int x)
{
    int ax, bx;

    gcd(x, MODULO, ax, bx);
    return ax;
}

vector<vector<int>> matmul(const vector<vector<int>>& a, const vector<vector<int>>& b)
{
    int n = (int)a.size();
    vector<vector<int>> re(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int k = 0; k < n; ++k)
        {
            int tmp = 0;
            for (int j = 0; j < n; ++j)
            {
                tmp = (tmp + a[i][j] * (long long)b[j][k] % MODULO) % MODULO;
            }
            re[i][k] = tmp;
        }
    return re;
}

vector<vector<int>> pow(const vector<vector<int>>& a, int k)
{
    if (k == 1)
    {
        return a;
    }

    vector<vector<int>> b = pow(a, k / 2);
    b = matmul(b, b);
    if (k % 2 == 1)
        b = matmul(a, b);

    return b;
}

int main()
{
    std::ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int invn = inv(n);
    int invnm1 = inv(n - 1);

    vector<int> a(n);
    vector<int> count(2);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ++count[a[i]];
    }

    int misplaced = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0 && i >= count[0] || a[i] == 1 && i < count[0])
        {
            ++misplaced;
        }
    }

    int misplaced_pair = misplaced / 2;
    int m = std::min(count[0], count[1]) + 1;

    vector<vector<int>> matrix(m, vector<int>(m));
    for (int i = 0; i < m; ++i)
    {
        int total = 0;
        if (i-1 >= 0)
        {
            int cur = (long long)i
                * i % MODULO
                * 2ll % MODULO
                * (long long)invn % MODULO
                * (long long)invnm1 % MODULO;
            matrix[i][i-1] = cur;
            total = (total + cur) % MODULO;
        }
        if (i+1 < m)
        {
            int cur = (long long)(count[0]-i)
                * (count[1]-i) % MODULO
                * 2ll % MODULO
                * (long long)invn % MODULO
                * (long long)invnm1 % MODULO;
            matrix[i][i+1] = cur;
            total = (total + cur) % MODULO;
        }
        matrix[i][i] = (1 - total + MODULO) % MODULO;
    }

    vector<vector<int>> p = pow(matrix, k);
    cout << p[misplaced_pair][0] << endl;

    return 0;
}