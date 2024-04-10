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
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};

int n, m;
char** a;

int** q;

void solv()
{
    cin >> n >> m;

    a = new char*[n + 5];
    for (int i = 0; i < n + 5; ++i)
        a[i] = new char[m + 5];

    for (int i = 1; i <= n; ++i)
        cin >> (a[i] + 1);

    q = new int*[n + 5];
    for (int i = 0; i < n + 5; ++i)
        q[i] = new int[m + 5];
    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= m; ++y)
        {
            q[x][y] = 0;
            for (int i = 0; i < 4; ++i)
            {
                int hx = x + xx[i];
                int hy = y + yy[i];
                if (1 <= hx && hx <= n && 1 <= hy && hy <= m && a[hx][hy] != '#')
                    ++q[x][y];
            }
        }
    }

    queue<pair<int, int> > u;
    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= m; ++y)
        {
            if (a[x][y] == 'L')
                u.push(m_p(x, y));
        }
    }

    while (!u.empty())
    {
        int x = u.front().fi;
        int y = u.front().se;
        u.pop();

        if (a[x][y] == '+')
            continue;

        if (a[x][y] != 'L')
            a[x][y] = '+';

        for (int i = 0; i < 4; ++i)
        {
            int hx = x + xx[i];
            int hy = y + yy[i];
            if (1 <= hx && hx <= n && 1 <= hy && hy <= m && a[hx][hy] != '#')
            {
                --q[hx][hy];
                if (q[hx][hy] <= 1 && a[hx][hy] != 'L')
                    u.push(m_p(hx, hy));
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            putchar(a[i][j]);
        putchar('\n');
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}