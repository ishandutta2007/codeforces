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
const char cc[4] = {'A', 'N', 'O', 'T'};

int n;
char a[N];

deque<int> v[4];

int t[N];
void ubd(int x, int y)
{
    while (x <= n)
    {
        t[x] += y;
        x += (x & (-x));
    }
}

int qry(int x)
{
    int ans = 0;
    while (x)
    {
        ans += t[x];
        x -= (x & (-x));
    }
    return ans;
}

char ans[N];

void solv()
{
    cin >> (a + 1);
    for (n = 1; a[n]; ++n){}
    --n;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (a[i] == cc[j])
            {
                a[i] = j;
                break;
            }
        }
    }

    int u[4] = {0, 1, 2, 3};
    int q[4] = {};
    for (int i = 1; i <= n; ++i)
        q[a[i]]++;
    ll ansq = -1;
    do
    {
        for (int i = 1; i <= n; ++i)
            ubd(i, 1);
        for (int i = 1; i <= n; ++i)
            v[a[i]].push_back(i);
        ll yansq = 0;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < q[u[i]]; ++j)
            {
                yansq += qry(v[u[i]].front()) - 1;
                ubd(v[u[i]].front(), -1);
                v[u[i]].pop_front();
            }
        }
        if (yansq > ansq)
        {
            ansq = yansq;
            int k = 0;
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < q[u[i]]; ++j)
                {
                    ans[++k] = cc[u[i]];
                }
            }
        }
    } while (next_permutation(u, u + 4));
    for (int i = 1; i <= n; ++i)
        cout << ans[i];
    cout << "\n";
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