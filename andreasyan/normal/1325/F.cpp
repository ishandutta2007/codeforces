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

int n, m;
vector<int> a[N];

int s;

bool c[N];

int d[N];
int p[N];

bool cc[N];
vector<int> ans;

void dfs(int x)
{
    c[x] = true;
    vector<int> v;
    bool z = true;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (c[h])
        {
            if (d[h] < d[x])
            {
                v.push_back(h);
            }
            else
            {
                if (cc[h])
                    z = false;
            }
        }
        else
        {
            d[h] = d[x] + 1;
            p[h] = x;
            dfs(h);
            if (cc[h])
                z = false;
        }
    }
    if (sz(v) >= s - 1)
    {
        int minu = N;
        int minh;
        for (int i = 0; i < v.size(); ++i)
        {
            int h = v[i];
            if (d[h] < minu)
            {
                minu = d[h];
                minh = h;
            }
        }
        vector<int> ans;
        while (1)
        {
            ans.push_back(x);
            if (x == minh)
                break;
            x = p[x];
        }
        printf("2\n");
        printf("%d\n", sz(ans));
        for (int i = 0; i < ans.size(); ++i)
            printf("%d ", ans[i]);
        printf("\n");
        exit(0);
    }
    else
    {
        if (z)
        {
            cc[x] = true;
            ans.push_back(x);
        }
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    s = sqrt(n);
    if (s * s < n)
        ++s;
    dfs(1);
    printf("1\n");
    for (int i = 0; i < s; ++i)
        printf("%d ", ans[i]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}