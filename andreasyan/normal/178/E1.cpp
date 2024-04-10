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
const int N = 2003;
const int xx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const int yy[8] = {1, 0, -1, 0, 1, -1, -1, 1};
struct ban
{
    int x, y;
    ban(){}
    ban(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
bool operator<(const ban& a, const ban& b)
{
    if (a.x < b.x)
        return true;
    if (a.x > b.x)
        return false;
    return a.y < b.y;
}

int n;
int a[N][N], b[N][N];

bool c[N][N];

vector<ban> v;
void dfs(int x, int y)
{
    c[x][y] = true;
    v.push_back(ban(x, y));
    for (int i = 0; i < 8; ++i)
    {
        int hx = x + xx[i];
        int hy = y + yy[i];
        if (hx >= 1 && hx <= n && hy >= 1 && hy <= n && a[hx][hy] && !c[hx][hy])
            dfs(hx, hy);
    }
}

double dist(ban t1, ban t2)
{
    return sqrt((t1.x - t2.x) * (t1.x - t2.x) + (t1.y - t2.y) * (t1.y - t2.y));
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int q = 0;
            for (int ii = i - 2; ii <= i + 2; ++ii)
            {
                for (int jj = j - 2; jj <= j + 2; ++jj)
                {
                    if (!(1 <= ii && ii <= n && 1 <= jj && jj <= n))
                        continue;
                    q += a[ii][jj];
                }
            }
            if (q > 5 * 5 / 2)
                b[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            a[i][j] = b[i][j];
        }
    }
    int qar = 0, shr = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (!c[i][j])
            {
                v.clear();
                dfs(i, j);
                if (sz(v) < 100)
                    continue;
                sort(all(v));
                double d = dist(v[0], v.back());
                double r = d / 2;
                double s = acos(-1.0) * r * r;
                if (abs((double)v.size() - s) <= (double)v.size() / 5)
                    ++shr;
                else
                    ++qar;
            }
        }
    }
    printf("%d %d\n", shr, qar);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    /*for (int i = 1; i <= 100; ++i)
    {
        for (int j = 1; j <= 100; ++j)
        {
            printf("1 ");
        }
        printf("\n");
    }
    return 0;*/
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}