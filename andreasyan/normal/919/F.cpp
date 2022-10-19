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

map<ll, int> c;

map<ll, int> qq;
map<ll, vector<ll> > g;

void pre()
{
    vector<vector<int> > vv;
    for (int q0 = 0; q0 <= 8; ++q0)
    {
        for (int q1 = 0; q1 <= 8 - q0; ++q1)
        {
            for (int q2 = 0; q2 <= 8 - q0 - q1; ++q2)
            {
                for (int q3 = 0; q3 <= 8 - q0 - q1 - q2; ++q3)
                {
                    int q4 = 8 - q0 - q1 - q2 - q3;
                    vv.push_back({q0, q1, q2, q3, q4});
                }
            }
        }
    }

    queue<ll> q;
    for (int i = 0; i < vv.size(); ++i)
    {
        for (int j = 0; j < vv.size(); ++j)
        {
            ll hv = 0;
            for (int k = 0; k < 5; ++k)
                hv = (hv * 10 + vv[i][k]);
            for (int k = 0; k < 5; ++k)
                hv = (hv * 10 + vv[j][k]);
            if (vv[i][0] == 8)
            {
                c[hv] = 1;
                q.push(hv);
                continue;
            }
            if (vv[j][0] == 8)
            {
                c[hv] = -1;
                q.push(hv);
                continue;
            }
            ll u[5];
            u[0] = 1000000000;
            for (int k = 1; k < 5; ++k)
                u[k] = u[k - 1] / 10;
            for (int k = 1; k < 5; ++k)
            {
                if (!vv[i][k])
                    continue;
                for (int kk = 1; kk < 5; ++kk)
                {
                    if (!vv[j][kk])
                        continue;
                    ll hh = hv;
                    hh -= (u[k]);
                    hh += (u[(k + kk) % 5]);
                    hh = (hh % 100000 * 100000 + hh / 100000);
                    g[hh].push_back(hv);
                    ++qq[hv];
                }
            }
        }
    }

    while (!q.empty())
    {
        ll x = q.front();
        q.pop();

        if (c[x] == 1)
        {
            for (int i = 0; i < g[x].size(); ++i)
            {
                ll h = g[x][i];
                --qq[h];
                if (qq[h] == 0)
                {
                    if (!c[h])
                    {
                        c[h] = -1;
                        q.push(h);
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < g[x].size(); ++i)
            {
                ll h = g[x][i];
                if (!c[h])
                {
                    c[h] = 1;
                    q.push(h);
                }
                else
                    assert(c[h] != -1);
            }
        }
    }
}

void solv()
{
    int ty;
    vector<int> v1, v2;
    cin >> ty;
    v1.assign(5, 0);
    v2.assign(5, 0);
    for (int i = 0; i < 8; ++i)
    {
        int x;
        cin >> x;
        v1[x]++;
    }
    for (int i = 0; i < 8; ++i)
    {
        int x;
        cin >> x;
        v2[x]++;
    }
    if (ty == 1)
        swap(v1, v2);

    ll hv = 0;
    for (int i = 0; i < 5; ++i)
        hv = (hv * 10 + v1[i]);
    for (int i = 0; i < 5; ++i)
        hv = (hv * 10 + v2[i]);

    if (c[hv] == 1)
    {
        if (ty == 0)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
    else if (c[hv] == -1)
    {
        if (ty == 0)
            cout << "Bob\n";
        else
            cout << "Alice\n";
    }
    else
        cout << "Deal\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}