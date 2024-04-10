#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 800005;

int n;
char s[N];

int z;
int t[N][26];
vector<int> a[N], b[N];

long long ans;
vector<pair<int, int> > ansv;

bool ca[N], cb[N];

void dfs(int pos, int d)
{
    for (int i = 0; i < 26; ++i)
    {
        if (t[pos][i])
            dfs(t[pos][i], d + 1);
    }
    while (1)
    {
        while (!a[pos].empty() && ca[a[pos].back()])
            a[pos].pop_back();
        while (!b[pos].empty() && cb[b[pos].back()])
            b[pos].pop_back();
        if (a[pos].empty() || b[pos].empty())
            break;
        ca[a[pos].back()] = true;
        cb[b[pos].back()] = true;
        ans += d;
        ansv.push_back(m_p(a[pos].back(), b[pos].back()));
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf(" %s", s);
        int m = strlen(s);
        int pos = 0;
        a[pos].push_back(i);
        for (int j = 0; j < m; ++j)
        {
            if (!t[pos][s[j] - 'a'])
            {
                t[pos][s[j] - 'a'] = ++z;
            }
            pos = t[pos][s[j] - 'a'];
            a[pos].push_back(i);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf(" %s", s);
        int m = strlen(s);
        int pos = 0;
        b[pos].push_back(i);
        for (int j = 0; j < m; ++j)
        {
            if (!t[pos][s[j] - 'a'])
            {
                t[pos][s[j] - 'a'] = ++z;
            }
            pos = t[pos][s[j] - 'a'];
            b[pos].push_back(i);
        }
    }
    dfs(0, 0);
    printf("%lld\n", ans);
    for (int i = 0; i < n; ++i)
        printf("%d %d\n", ansv[i].first, ansv[i].second);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}