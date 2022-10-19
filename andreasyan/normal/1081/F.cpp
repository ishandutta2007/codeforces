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
const int N = 303;

int n, t;

int c[N];

int qry(int l, int r)
{
    if (!(1 <= l && l <= r && r <= n))
    {
        while (1){}
    }
    cout << "? " << l << ' ' << r << endl;
    int ans;
    cin >> ans;
    if (ans == -1)
    {
        while (1){}
    }
    if (r % 2 == abs(ans - t) % 2)
    {
        for (int i = 1; i <= r; ++i)
            c[i] ^= 1;
    }
    else
    {
        for (int i = l; i <= n; ++i)
            c[i] ^= 1;
    }
    return ans;
}

int ans[N];

void solv()
{
    cin >> n >> t;

    if (n == 1)
    {
        cout << "! " << t << endl;
        return;
    }

    if (n % 2 == 0)
    {
        for (int i = 1; i <= n; ++i)
        {
            int u = i;
            if ((i % 2) == (n - u + 1) % 2)
                --u;
            while (1)
            {
                int nt = qry(u, i);
                if (abs(t - nt) % 2 == i % 2)
                {
                    int u = nt - t;
                    for (int j = 1; j < i; ++j)
                    {
                        if ((ans[j] ^ c[j]) == 1)
                            --u;
                        else
                            ++u;
                    }
                    if (u == 1)
                        ans[i] = (1 ^ c[i]);
                    else
                        ans[i] = c[i];
                    t = nt;
                    break;
                }
                t = nt;
            }
        }
    }
    else
    {
        while (1)
        {
            int nt = qry(1, 2);
            if (abs(t - nt) % 2 == 0)
            {
                if (nt == t)
                {
                    t = qry(2, 3);
                    continue;
                }
                if (nt > t)
                {
                    ans[1] = (1 ^ c[1]);
                    ans[2] = (1 ^ c[2]);
                }
                else
                {
                    ans[1] = c[1];
                    ans[2] = c[2];
                }
                t = nt;
                break;
            }
            t = nt;
        }
        for (int i = 3; i <= n; ++i)
        {
            int u = i;
            if ((i % 2) == (n - u + 1) % 2)
                --u;
            while (1)
            {
                int nt = qry(u, i);
                if (abs(t - nt) % 2 == i % 2)
                {
                    int u = nt - t;
                    for (int j = 1; j < i; ++j)
                    {
                        if ((ans[j] ^ c[j]) == 1)
                            --u;
                        else
                            ++u;
                    }
                    if (u == 1)
                        ans[i] = (1 ^ c[i]);
                    else
                        ans[i] = c[i];
                    t = nt;
                    break;
                }
                t = nt;
            }
        }
    }

    cout << "! ";
    for (int i = 1; i <= n; ++i)
        cout << ans[i];
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