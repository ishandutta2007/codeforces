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
const int N = 102;

int qry1(int x, int y)
{
    cout << "1 " << x << ' ' << y << endl;
    int ans;
    cin >> ans;
    return ans;
}

vector<int> rec(int l, int r)
{
    vector<int> v;
    if (l == r)
    {
        v.push_back(l);
        return v;
    }

    int m = (l + r) / 2;

    vector<int> v1 = rec(l, m);
    vector<int> v2 = rec(m + 1, r);

    int i = 0, j = 0;
    bool z;
    if (qry1(v1[i], v2[j]) == 1)
        z = false;
    else
        z = true;
    while (1)
    {
        if (i == sz(v1) && j == sz(v2))
            break;
        if (i == sz(v1))
        {
            v.push_back(v2[j++]);
            continue;
        }
        if (j == sz(v2))
        {
            v.push_back(v1[i++]);
            continue;
        }

        if (!z)
            v.push_back(v1[i++]);
        else
            v.push_back(v2[j++]);
        if (i < sz(v1) && j < sz(v2))
        {
            if (qry1(v1[i], v2[j]) == 1)
                z = false;
            else
                z = true;
        }
    }

    return v;
}

int u[N];

void solv()
{
    int n;
    cin >> n;

    vector<int> v = rec(0, n - 1);

    /*for (int i = 0; i < sz(v); ++i)
        cout << v[i] << ' ';
    cout << endl;
    return;*/

    vector<int> s;
    for (int i = sz(v) - 1; i >= 0; --i)
    {
        int x = v[i];
        u[x] = i;
        while (!s.empty())
        {
            cout << "2 " << s.back() << ' ' << i + 1 << ' ';
            for (int j = 0; j <= i; ++j)
                cout << v[j] << ' ';
            cout << endl;
            int ans;
            cin >> ans;

            if (ans == 1)
            {
                assert(u[v[i + 1]] == u[s.back()]);
                u[x] = u[v[i + 1]];
                break;
            }
            else
                s.pop_back();
        }
        s.push_back(x);
    }

    cout << '3' << endl;
    for (int x = 0; x < n; ++x)
    {
        for (int y = 0; y < n; ++y)
        {
            if (u[x] <= u[y])
                cout << '1';
            else
                cout << '0';
        }
        cout << endl;
    }

    int correct;
    cin >> correct;
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