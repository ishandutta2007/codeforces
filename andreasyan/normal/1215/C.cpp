#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005;

int n;
char a[N], b[N];

vector<int> ab, ba;

int main()
{
    scanf("%d %s %s", &n, a + 1, b + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 'a' && b[i] == 'b')
            ab.push_back(i);
        else if (a[i] == 'b' && b[i] == 'a')
            ba.push_back(i);
    }
    if (ab.size() % 2 != ba.size() % 2)
    {
        printf("-1\n");
        return 0;
    }
    vector<pair<int, int> > ans;
    while (ab.size() > 1)
    {
        ans.push_back(m_p(ab[ab.size() - 1], ab[ab.size() - 2]));
        ab.pop_back();
        ab.pop_back();
    }
    while (ba.size() > 1)
    {
        ans.push_back(m_p(ba[ba.size() - 1], ba[ba.size() - 2]));
        ba.pop_back();
        ba.pop_back();
    }
    if (!ab.empty())
    {
        ans.push_back(m_p(ab[0], ab[0]));
        ans.push_back(m_p(ab[0], ba[0]));
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}