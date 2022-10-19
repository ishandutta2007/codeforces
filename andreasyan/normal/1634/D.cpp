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
const int N = 1003;

int qry(int i, int j, int k)
{
    cout << "? " << i << ' ' << j << ' ' << k << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solv()
{
    int n;
    cin >> n;

    int i = 1, j = 2, k = 3;
    int t = qry(i, j, k);
    for (int u = 4; u <= n; ++u)
    {
        int t1 = qry(i, k, u);
        int t2 = qry(j, k, u);

        if (t >= t1 && t >= t2)
            continue;

        if (t1 > t2)
        {
            j = u;
            t = t1;
        }
        else
        {
            i = u;
            t = t2;
        }
    }

    int u;
    for (u = 1; u <= n; ++u)
    {
        if (u != i && u != j && u != k)
            break;
    }

    if (qry(i, j, u) == t)
    {
        cout << "! " << i << ' ' << j << endl;
        return;
    }
    if (qry(i, k, u) == t)
    {
        cout << "! " << i << ' ' << k << endl;
        return;
    }
    cout << "! " << j << ' ' << k << endl;
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