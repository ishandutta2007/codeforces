#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005;
const int M = 1000000007;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int n;
string a;
int q;
pair<char, string> b[N];

int qn[N][10], x[N][10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a;
    n = a.size();
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        string a;
        cin >> a;
        int n = a.size();
        b[i].first = a[0];
        for (int j = 3; j < n; ++j)
            b[i].second += a[j];
    }
    b[0].first = '0';
    b[0].second = a;
    for (int j = 0; j < 10; ++j)
    {
        qn[q + 1][j] = 1;
        x[q + 1][j] = j;
    }
    for (int i = q; i >= 0; --i)
    {
        for (int j = 0; j < 10; ++j)
        {
            qn[i][j] = qn[i + 1][j];
            x[i][j] = x[i + 1][j];
        }
        int j = b[i].first - '0';
        int m = b[i].second.size();
        qn[i][j] = 0;
        x[i][j] = 0;
        for (int k = m - 1; k >= 0; --k)
        {
            x[i][j] = (x[i][j] + ast(10, qn[i][j]) * 1LL * x[i + 1][b[i].second[k] - '0']) % M;
            qn[i][j] = (qn[i][j] + qn[i + 1][b[i].second[k] - '0']) % (M - 1);
        }
    }
    printf("%d\n", x[0][0]);
    return 0;
}