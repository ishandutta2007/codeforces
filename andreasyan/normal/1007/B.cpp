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

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

struct ban
{
    int x, y, z;
};

vector<ban> v;
int q[N];
vector<int> vv[N];

void pre()
{
    for (int x = 0; x < (1 << 3); ++x)
    {
        for (int y = x; y < (1 << 3); ++y)
        {
            for (int z = y; z < (1 << 3); ++z)
            {
                int u[3];
                u[0] = x;
                u[1] = y;
                u[2] = z;
                bool f = false;
                do
                {
                    bool ff = true;
                    for (int i = 0; i < 3; ++i)
                    {
                        if (!(u[i] & (1 << i)))
                        {
                            ff = false;
                            break;
                        }
                    }
                    if (ff)
                    {
                        f = true;
                        break;
                    }
                } while (next_permutation(u, u + 3));
                if (f)
                    v.push_back({x, y, z});
            }
        }
    }
    for (int i = 1; i < N; ++i)
    {
        for (int j = i; j < N; j += i)
        {
            ++q[j];
            vv[j].push_back(i);
        }
    }
}

int qq[(1 << 3)];

int a[3];

void solv()
{
    for (int x = (1 << 3) - 1; x >= 1; --x)
    {
        int g = 0;
        int rx = 0;
        for (int i = 0; i < 3; ++i)
        {
            if ((x & (1 << i)))
                g = gcd(g, a[i]);
            else
                rx |= (1 << i);
        }
        qq[x] = q[g];
        for (int y = rx; y; y = ((y - 1) & rx))
            qq[x] -= qq[(x | y)];
    }
    int ans = 0;
    for (int i = 0; i < sz(v); ++i)
    {
        int nans = ans;
        if (v[i].x == v[i].y && v[i].y == v[i].z)
            ans += qq[v[i].x] * (qq[v[i].y] + 1) * (qq[v[i].z] + 2) / 6;
        else if (v[i].x == v[i].y || v[i].y == v[i].z)
            ans += qq[v[i].x] * (qq[v[i].y] + 1) * qq[v[i].z] / 2;
        else
            ans += qq[v[i].x] * qq[v[i].y] * qq[v[i].z];
    }
    printf("%d\n", ans);
}

void solv0()
{
    set<multiset<int> > ss;
    for (int i = 0; i < vv[a[0]].size(); ++i)
    {
        for (int j = 0; j < vv[a[1]].size(); ++j)
        {
            for (int k = 0; k < vv[a[2]].size(); ++k)
            {
                multiset<int> s;
                s.insert(vv[a[0]][i]);
                s.insert(vv[a[1]][j]);
                s.insert(vv[a[2]][k]);
                ss.insert(s);
            }
        }
    }
    printf("%d\n", ss.size());
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    pre();
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        for (int i = 0; i < 3; ++i)
            scanf("%d", &a[i]);
        solv();
        //solv0();
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}