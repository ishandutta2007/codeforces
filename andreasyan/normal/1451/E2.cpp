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
const int N = (1 << 18);

int n, m;

int aa[N] = {-1, 3, 1, 0, 2};

int qry(string s, int i, int j)
{
    /*if (s == "XOR")
        return (aa[i] ^ aa[j]);
    if (s == "OR")
        return (aa[i] | aa[j]);
    return (aa[i] & aa[j]);*/
    cout << s << ' ' << i << ' ' << j << endl;
    int ans;
    cin >> ans;
    return ans;
}

int x[N];

int u[N];

int a[N];

void solv()
{
    cin >> n;
    while ((1 << m) < n)
        ++m;

    for (int i = 2; i <= n; ++i)
    {
        x[i] = qry("XOR", 1, i);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!u[x[i]])
            u[x[i]] = i;
        else
        {
            a[i] = qry("AND", i, u[x[i]]);
            for (int j = 1; j <= n; ++j)
            {
                if (j == i)
                    continue;
                a[j] = (a[i] ^ x[i] ^ x[j]);
            }
            cout << "! ";
            for (int i = 1; i <= n; ++i)
                cout << a[i] << ' ';
            cout << endl;
            return;
        }
    }

    int q1 = qry("AND", 1, u[1]);
    int q2 = qry("AND", 1, u[2]);

    for (int i = 0; i < m; ++i)
    {
        if (i == 0)
            a[1] += ((1 << i) & q2);
        else
            a[1] += ((1 << i) & q1);
    }

    for (int i = 2; i <= n; ++i)
        a[i] = (a[1] ^ x[i]);

    cout << "! ";
    for (int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    cout << endl;
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}