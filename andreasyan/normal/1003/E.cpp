#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 400005;

int nn, d, k;

int n;
int q[N];
int t[N];

vector<pair<int, int> > ans;

int main()
{
    scanf("%d%d%d", &nn, &d, &k);
    ++d;
    n = d;
    for (int i = 1; i < n; ++i)
        ans.push_back(m_p(i, i + 1));
    for (int i = 2; i < d; ++i)
    {
        q[i] = 2;
    }
    if (n > 1)
        q[1] = q[n] = 1;
    for (int i = 1; i <= n; ++i)
    {
        t[i] = min(i - 1, n - i);
    }
    int x = 1;
    while (n < nn)
    {
        while (x < n && (t[x] == 0 || q[x] == k))
            ++x;
        if (t[x] == 0 || q[x] == k)
            break;
        q[x]++;
        ans.push_back(m_p(x, ++n));
        q[n] = 1;
        t[n] = t[x] - 1;
    }
    if (n != nn)
    {
        printf("NO\n");
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (q[i] > k)
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    assert(ans.size() == n - 1);
    for (int i = 0; i < n - 1; ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}