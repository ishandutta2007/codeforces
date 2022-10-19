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
const int N = 1000006;

int n;
char a[N];

int u0[N], u1[N];

vector<int> v[N];
int p[N];

int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

void solv()
{
    scanf("%d", &n);
    scanf(" %s", (a + 1));
    for (int i = n; i >= 1; --i)
    {
        if (a[i] == '?')
        {
            u0[i] = u0[i + 1] + 1;
            u1[i] = u1[i + 1] + 1;
        }
        else if (a[i] == '0')
        {
            u0[i] = u0[i + 1] + 1;
            u1[i] = 0;
        }
        else
        {
            u0[i] = 0;
            u1[i] = u1[i + 1] + 1;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        v[max(u0[i], u1[i])].push_back(i);
    }
    for (int i = 1; i <= n + 1; ++i)
        p[i] = i;

    for (int x = 1; x <= n; ++x)
    {
        int ans = 0;
        int i = 1;
        while (1)
        {
            i = fi(i);
            if (i == n + 1)
                break;
            ++ans;
            i += x;
        }
        printf("%d ", ans);
        for (int j = 0; j < v[x].size(); ++j)
        {
            int i = v[x][j];
            p[i] = i + 1;
        }
    }
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