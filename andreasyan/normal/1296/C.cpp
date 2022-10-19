#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005;

int n;
char a[N];

int p1[N], p2[N];

void solv()
{
    scanf("%d", &n);
    scanf(" %s", (a + 1));
    for (int i = 1; i <= n; ++i)
    {
        p1[i] = p1[i - 1];
        p2[i] = p2[i - 1];
        if (a[i] == 'L')
            p1[i]--;
        else if (a[i] == 'R')
            p1[i]++;
        else if (a[i] == 'U')
            p2[i]++;
        else
            p2[i]--;
    }
    map<pair<int, int>, int> mp;
    int l = 0, r = N;
    for (int i = 0; i <= n; ++i)
    {
        if (mp.find(m_p(p1[i], p2[i])) != mp.end())
        {
            int j = mp[m_p(p1[i], p2[i])];
            ++j;
            if (i - j + 1 < (r - l + 1))
            {
                r = i;
                l = j;
            }
        }
        mp[m_p(p1[i], p2[i])] = i;
    }
    if (r == N)
        printf("-1\n");
    else
        printf("%d %d\n", l, r);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}