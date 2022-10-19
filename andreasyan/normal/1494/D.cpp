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
const int N = 502;

int n;
int a[N][N];

int k;
int s[N * 2];
int u[N * 2];

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

    k = n;
    for (int i = 1; i <= n; ++i)
    {
        s[i] = a[i][i];
        u[i] = i;
    }

    vector<pair<int, int> > ans;
    vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(i);
    while (1)
    {
        if (sz(v) == 1)
            break;
        int minu = N * N;
        int mini;
        int minj;
        for (int i = 0; i < sz(v); ++i)
        {
            for (int j = i + 1; j < sz(v); ++j)
            {
                if (a[u[v[i]]][u[v[j]]] < minu || (a[u[v[i]]][u[v[j]]] == minu && (s[v[i]] == minu || s[v[j]] == minu)))
                {
                    minu = a[u[v[i]]][u[v[j]]];
                    mini = i;
                    minj = j;
                }
            }
        }
        if (minu == s[v[mini]])
        {
            ans.push_back(m_p(v[minj], v[mini]));
            vector<int> vv;
            for (int i = 0; i < sz(v); ++i)
            {
                if (i == minj)
                    continue;
                vv.push_back(v[i]);
            }
            v = vv;
        }
        else if (minu == s[v[minj]])
        {
            ans.push_back(m_p(v[mini], v[minj]));
            vector<int> vv;
            for (int i = 0; i < sz(v); ++i)
            {
                if (i == mini)
                    continue;
                vv.push_back(v[i]);
            }
            v = vv;
        }
        else
        {
            ++k;
            ans.push_back(m_p(v[mini], k));
            ans.push_back(m_p(v[minj], k));
            u[k] = u[v[mini]];
            s[k] = minu;
            vector<int> vv;
            for (int i = 0; i < sz(v); ++i)
            {
                if (i == mini || i == minj)
                    continue;
                vv.push_back(v[i]);
            }
            vv.push_back(k);
            v = vv;
        }
    }

    printf("%d\n", k);
    for (int i = 1; i <= k; ++i)
        printf("%d ", s[i]);
    printf("\n");
    printf("%d\n", v[0]);
    assert(sz(ans) == k - 1);
    for (int i = 0; i < sz(ans); ++i)
        printf("%d %d\n", ans[i].fi, ans[i].se);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}