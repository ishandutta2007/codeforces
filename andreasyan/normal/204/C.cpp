#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005, INF = 1000000009;

int n;
char a[N], b[N];

long long p[N][26], s[N][26];

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(9);
    scanf("%d", &n);
    scanf(" %s %s", (a + 1), (b + 1));
    for (int i = 1; i <= n; ++i)
    {
        a[i] = a[i] - 'A';
        b[i] = b[i] - 'A';
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 26; ++j)
            p[i][j] = p[i - 1][j];
        p[i][b[i]] += i;
    }
    for (int i = n; i >= 1; --i)
    {
        for (int j = 0; j < 26; ++j)
            s[i][j] = s[i + 1][j];
        s[i][b[i]] += (n - i + 1);
    }
    long double ans2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans2 += (n - i + 1) * 1LL * (n - i + 1);
    }
    long double yans = 0;
    for (int i = 1; i <= n; ++i)
    {
        yans += (p[i][a[i]] / ans2) * (n - i + 1);
        yans += (s[i + 1][a[i]] / ans2) * i;
    }
    cout << yans << endl;
    return 0;
}