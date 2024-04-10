#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair

int n;
int nn;

int a, b, c;

void solv()
{
    scanf("%d", &n);
    nn = n;
    vector<pair<int, int> > v;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            int q = 0;
            while (n % i == 0)
            {
                n /= i;
                ++q;
            }
            v.push_back(m_p(i, q));
        }
    }
    if (n > 1)
        v.push_back(m_p(n, 1));
    n = nn;
    if (v.size() >= 2)
    {
        a = v[0].first;
        b = v[1].first;
        c = n / a / b;
        if (a >= 2 && b >= 2 && c >= 2 && a != b && b != c && c != a)
        {
            printf("YES\n%d %d %d\n", a, b, c);
        }
        else
        {
            printf("NO\n");
        }
    }
    else
    {
        if (v[0].second >= 6)
        {
            int a = v[0].first;
            int b = v[0].first * v[0].first;
            int c = n / a / b;
            printf("YES\n%d %d %d\n", a, b, c);
        }
        else
            printf("NO\n");
    }
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}