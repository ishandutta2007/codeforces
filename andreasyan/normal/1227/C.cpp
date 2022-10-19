#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 2003;

int n, k;
char a[N];

vector<pair<int, int> > ans;
char aa[N];
void rev(int l, int r)
{
    ans.push_back(m_p(l, r));
    for (int i = l; i <= r; ++i)
        aa[i] = a[i];
    for (int i = l, j = r; i <= r; ++i, --j)
        a[i] = aa[j];
}

char b[N];

void solv()
{
    scanf("%d%d", &n, &k);
    scanf(" %s", a);
    ans.clear();
    for (int i = 0; i < k - 1; ++i)
    {
        b[i * 2] = '(';
        b[i * 2 + 1] = ')';
    }
    for (int i = (k - 1) * 2, j = n - 1; ; ++i, --j)
    {
        if (i > j)
            break;
        b[i] = '(';
        b[j] = ')';
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (a[j] == b[i])
            {
                rev(i, j);
                break;
            }
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}