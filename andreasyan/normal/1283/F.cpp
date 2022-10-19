#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005;

int n;
int a[N];

int r;
bool c[N];

vector<pair<int, int> > ans;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; ++i)
    {
        scanf("%d", &a[i]);
    }
    r = a[1];
    int x = r;
    c[x] = true;
    int j = n;
    for (int i = 2; i < n; ++i)
    {
        while (c[j] == true)
            --j;
        if (a[i] == j || c[a[i]])
        {
            ans.push_back(m_p(x, j));
            x = a[i];
            c[ans.back().first] = c[ans.back().second] = true;
        }
        else
        {
            ans.push_back(m_p(x, a[i]));
            x = a[i];
            c[ans.back().first] = c[ans.back().second] = true;
        }
    }
    while (c[j] == true)
        --j;
    ans.push_back(m_p(x, j));
    printf("%d\n", r);
    for (int i = 0; i < n - 1; ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}