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
const int N = 203;

char ans[N][N];
char qry(int x, int y)
{
    if (ans[x][y])
        return ans[x][y];
    cout << "? " << x << ' ' << y << endl;
    cin >> ans[x][y];
    return ans[x][y];
}

void solv()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n * 2; ++i)
        for (int j = 1; j <= n * 2; ++j)
            ans[i][j] = 0;

    int u1, t1, u2, t2;
    u1 = 1;
    t1 = 2;
    u2 = 3;

    if (qry(u1, t1) == '<')
        swap(u1, t1);

    for (int i = 4; i <= n * 2; ++i)
    {
        t2 = i;

        if (qry(u2, t2) == '<')
            swap(u2, t2);

        if (qry(t1, t2) == '<')
        {
            swap(t1, t2);
            swap(u1, u2);
        }

        vector<int> v;
        for (int j = 1; j <= n * 2; ++j)
        {
            if (j == t2)
                continue;
            if (qry(t2, j) == '>')
                v.push_back(j);
        }

        if (sz(v) >= n)
        {
            for (int i = 0; i < sz(v); ++i)
            {
                for (int j = i + 1; j < sz(v); ++j)
                    qry(v[i], v[j]);
            }
            cout << '!' << endl;
            return;
        }
    }

    cout << '!' << endl;
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
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