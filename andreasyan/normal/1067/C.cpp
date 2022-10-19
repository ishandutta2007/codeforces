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
const int xx[8] = {1, 2, -1, 2, 1, -2, -1, -2};
const int yy[8] = {2, 1, 2, -1, -2, 1, -2, -1};

int stg(vector<pair<int, int> > v)
{
    map<pair<int, int>, int> c;
    queue<pair<int, int> > q;
    for (int i = 0; i < sz(v); ++i)
    {
        c[v[i]] = 4;
        q.push(v[i]);
    }

    int ans = 0;
    while (!q.empty())
    {
        ++ans;
        pair<int, int> t = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i)
        {
            pair<int, int> h = t;
            h.fi += xx[i];
            h.se += yy[i];
            ++c[h];
            if (c[h] == 4)
                q.push(h);
        }
    }

    return ans;
}

int n;

int solv()
{
    vector<pair<int, int> > v;

    for (int i = 0; i < (n / 3) * 2; ++i)
    {
        cout << "0 " << i << "\n";
        v.push_back(m_p(0, i));
    }
    for (int i = 0; i < (n / 3) + n % 3; ++i)
    {
        cout << "3 " << i * 2 << "\n";
        v.push_back(m_p(3, i * 2));
    }

    int q = stg(v);
    //cout << q << "\n";
    return q;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    /*for (n = 1; n <= 100; ++n)
    {
        cout << (double)n * n / solv() << "\n";
    }
    return 0;*/

    cin >> n;
    solv();
    return 0;
}