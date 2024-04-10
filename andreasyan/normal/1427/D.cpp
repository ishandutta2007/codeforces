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
const int N = 55;

int n;
int a[N];

vector<vector<int> > ans;
void ubd(vector<int> v)
{
    vector<int> vv;
    for (int i = 0; i < sz(v); ++i)
    {
        if (v[i])
            vv.push_back(v[i]);
    }
    v = vv;

    if (sz(v) == 1)
        return;

    ans.push_back(v);

    vector<vector<int> > u;
    int s = 1;
    for (int i = 0; i < sz(v); ++i)
    {
        vector<int> t;
        for (int j = s; j < s + v[i]; ++j)
            t.push_back(a[j]);
        u.push_back(t);
        s += v[i];
    }
    reverse(all(u));
     s = 1;
    for (int i = 0; i < sz(u); ++i)
    {
        for (int j = 0; j < sz(u[i]); ++j)
            a[s++] = u[i][j];
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    while (1)
    {
        bool z = true;
        for (int i = 1; i < n; ++i)
        {
            if (a[i + 1] != (a[i] % n + 1))
            {
                z = false;
                break;
            }
        }
        if (z)
            break;
        int u;
        if (a[1] == 1)
            u = n;
        else
            u = a[1] - 1;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == u)
            {
                for (int j = i; ; --j)
                {
                    if (a[j] != (a[j - 1] % n + 1))
                    {
                        ubd({j - 1, i - j + 1, n - i});
                        break;
                    }
                }
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 1)
        {
            ubd({i - 1, n - i + 1});
            break;
        }
    }

    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); ++i)
    {
        printf("%d ", sz(ans[i]));
        for (int j = 0; j < sz(ans[i]); ++j)
            printf("%d ", ans[i][j]);
        printf("\n");
    }

    /*for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");*/
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