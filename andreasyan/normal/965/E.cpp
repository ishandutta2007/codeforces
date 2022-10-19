#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n;
char a[N];

int z;
int t[N][26];
bool c[N];

multiset<int> s[N];

void dfs(int x, int yd)
{
    for (int i = 0; i < 26; ++i)
    {
        if (t[x][i] == 0)
            continue;
        int h = t[x][i];
        dfs(h, yd + 1);
        for (auto it = s[h].begin(); it != s[h].end(); ++it)
        {
            s[x].insert(*it);
        }
    }
    if (c[x])
    {
        s[x].insert(yd);
        return;
    }
    s[x].erase(--s[x].end());
    s[x].insert(yd);
}

void solv()
{
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        scanf(" %s", a);
        n = strlen(a);
        int pos = 0;
        for (int i = 0; i < n; ++i)
        {
            if (t[pos][a[i] - 'a'] == 0)
                t[pos][a[i] - 'a'] = ++z;
            pos = t[pos][a[i] - 'a'];
        }
        c[pos] = true;
    }
    c[0] = true;
    dfs(0, 0);
    int ans = 0;
    for (auto it = s[0].begin(); it != s[0].end(); ++it)
        ans += *it;
    printf("%d\n", ans);
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