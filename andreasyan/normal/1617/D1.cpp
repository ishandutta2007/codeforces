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

int qry(int x, int y, int z)
{
    cout << "? " << x << ' ' << y << ' ' << z << endl;
    int ans;
    cin >> ans;
    return ans;
}

int t[N];

int ans[N];

void solv()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i += 3)
    {
        t[i] = qry(i, i + 1, i + 2);
    }

    int u[2];

    for (int i = 1; i <= n; i += 3)
    {
        if (t[i] != t[i + 3])
        {
            t[i + 1] = qry(i + 1, i + 2, i + 3);
            t[i + 2] = qry(i + 2, i + 3, i + 4);
            for (int j = i; j < i + 3; ++j)
            {
                if (t[j] != t[j + 1])
                {
                    u[t[j]] = j;
                    u[t[j + 1]] = j + 3;
                    break;
                }
            }
            break;
        }
    }

    ans[u[0]] = 0;
    ans[u[1]] = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (i == u[1] || i == u[0])
            continue;
        ans[i] = qry(u[0], u[1], i);
    }

    /*for (int i = 1; i <= n; i += 3)
    {
        if (qry(i, i + 1, u[(t[i] ^ 1)] == t[i])
        {
            ans[i] = ans[i + 1] = t[i];
            ans[i + 2] = qry(u[0], u[1], i + 2);
        }
    }*/

    vector<int> yans;
    for (int i = 1; i <= n; ++i)
    {
        if (ans[i] == 0)
            yans.push_back(i);
    }

    cout << "! " << sz(yans) << ' ';
    for (int i = 0; i < sz(yans); ++i)
        cout << yans[i] << ' ';
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