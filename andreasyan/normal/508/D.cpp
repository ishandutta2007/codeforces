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
const int N = 200005, M = 62;

int n;

int ctoi(char x)
{
    if ('a' <= x && x <= 'z')
        return x - 'a';
    if ('A' <= x && x <= 'Z')
        return 26 + x - 'A';
    return 26 + 26 + x - '0';
}

char itoc(int x)
{
    if (0 <= x && x < 26)
        return x + 'a';
    if (26 <= x && x < 26 + 26)
        return x - 26 + 'A';
    return x - 26 - 26 + '0';
}

int q[M * M];
vector<int> g[M * M];
vector<int> gi[M * M];

bool c[N];

vector<int> ans;

void dfs(int x)
{
    while (1)
    {
        if (g[x].empty())
            break;
        int h = g[x].back();
        int hi = gi[x].back();
        g[x].pop_back();
        gi[x].pop_back();
        if (c[hi])
            continue;
        c[hi] = true;
        dfs(h);
    }
    ans.push_back(x);
}

char yans[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        char s[5];
        scanf(" %s", s);
        int x = ctoi(s[0]) * M + ctoi(s[1]);
        int y = ctoi(s[1]) * M + ctoi(s[2]);
        g[x].push_back(y);
        gi[x].push_back(i);
        ++q[x];
        --q[y];
    }
    int qq = 0;
    for (int i = 0; i < M * M; ++i)
    {
        if (q[i])
            ++qq;
    }
    if (!qq)
    {
        for (int i = 0; i < M * M; ++i)
        {
            if (!g[i].empty())
            {
                dfs(i);
                break;
            }
        }
    }
    else if (qq == 2)
    {
        for (int i = 0; i < M * M; ++i)
        {
            if (q[i] == 1)
            {
                dfs(i);
                break;
            }
        }
    }
    n += 2;
    if (ans.size() != n - 1)
    {
        printf("NO\n");
        return;
    }
    reverse(all(ans));
    yans[0] = itoc(ans[0] / M);
    for (int i = 0; i < n - 1; ++i)
        yans[i + 1] = itoc(ans[i] % M);
    printf("YES\n");
    printf("%s\n", yans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}