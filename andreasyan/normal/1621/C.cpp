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
const int N = 10004;

int n;
int p[N];
int q[N];
int nq[N];

int qq;
int qry(int x)
{
    ++qq;
    cout << "? " << x << endl;

    int ans = q[x];
    /*for (int i = 1; i <= n; ++i)
        nq[i] = q[p[i]];

    for (int i = 1; i <= n; ++i)
        q[i] = nq[i];
    return ans;*/

    cin >> ans;
    return ans;
}

bool c[N];

int ans[N];
void solv()
{
    qq = 0;
    cin >> n;
    //for (int i = 1; i <= n; ++i)
    //    cin >> p[i];

    for (int i = 1; i <= n; ++i)
        q[i] = i;

    int cq = 0;
    for (int i = 1; i <= n; ++i)
        c[i] = false;

    qry(1);
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
            continue;

        vector<int> v;
        while (1)
        {
            if (cq == n)
                break;
            int x = qry(i);
            if (c[x])
                break;
            v.push_back(x);
            c[x] = true;
            ++cq;
        }

        for (int i = 0; i < sz(v); ++i)
        {
            ans[v[i]] = v[(i + 1) % sz(v)];
        }
    }

    cout << "! ";
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << endl;
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