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

int n;
int q[4];

void tp(int x)
{
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < 4; ++j)
            {
                if ((x & (1 << j)) && q[j])
                {
                    cout << j << ' ';
                    --q[j];
                    break;
                }
            }
        }
        else
        {
            for (int j = 0; j < 4; ++j)
            {
                if (!(x & (1 << j)) && q[j])
                {
                    cout << j << ' ';
                    --q[j];
                    break;
                }
            }
        }
    }
}

void solv()
{
    for (int i = 0; i < 4; ++i)
    {
        cin >> q[i];
        n += q[i];
    }

    if (q[0] == 0 && q[3] == 0)
    {
        if (abs(q[1] - q[2]) <= 1)
        {
            cout << "YES\n";
            if (q[1] > q[2])
                tp((1 << 1));
            else
                tp((1 << 2));
        }
        else
        {
            cout << "NO\n";
        }
        return;
    }
    if (q[0] == 0)
    {
        if (abs(q[2] - (q[1] + q[3])) <= 1)
        {
            cout << "YES\n";
            if (q[2] > (q[1] + q[3]))
                tp((1 << 2));
            else
                tp(((1 << 1) | (1 << 3)));
        }
        else
        {
            cout << "NO\n";
        }
        return;
    }
    if (q[3] == 0)
    {
        if (abs(q[1] - (q[0] + q[2])) <= 1)
        {
            cout << "YES\n";
            if (q[1] > (q[0] + q[2]))
                tp((1 << 1));
            else
                tp(((1 << 0) | (1 << 2)));
        }
        else
        {
            cout << "NO\n";
        }
        return;
    }

    if (q[1] < q[0] - 1)
    {
        cout << "NO\n";
        return;
    }
    if (q[2] < q[3] - 1)
    {
        cout << "NO\n";
        return;
    }

    q[1] -= (q[0] - 1);
    q[2] -= (q[3] - 1);

    if (q[1] >= 1 && q[2] >= 1 && abs(q[1] - q[2]) <= 1)
    {
        cout << "YES\n";

        vector<int> ans;
        ans.push_back(0);
        for (int i = 0; i < q[0] - 1; ++i)
        {
            ans.push_back(1);
            ans.push_back(0);
        }

        for (int i = 0; i < min(q[1], q[2]); ++i)
        {
            ans.push_back(1);
            ans.push_back(2);
        }

        ans.push_back(3);
        for (int i = 0; i < q[3] - 1; ++i)
        {
            ans.push_back(2);
            ans.push_back(3);
        }

        if (q[2] > q[1])
            ans.push_back(2);
        else if (q[1] > q[2])
        {
            reverse(all(ans));
            ans.push_back(1);
        }

        for (int i = 0; i < sz(ans); ++i)
            cout << ans[i] << ' ';
        cout << "\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}