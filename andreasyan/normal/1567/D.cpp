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
const int INF = 1000000009;

int n, q;

void solv()
{
    cin >> n >> q;

    vector<int> v;

    int u = 1;
    while (n)
    {
        for (int i = 0; i < n % 10; ++i)
            v.push_back(u);
        u *= 10;
        n /= 10;
    }

    while (1)
    {
        if (sz(v) >= q)
        {
            while (sz(v) > q)
            {
                v[0] += v.back();
                v.pop_back();
            }
            break;
        }
        else
        {
            int minu = INF;
            int mini;
            for (int i = 0; i < sz(v); ++i)
            {
                if (v[i] != 1)
                {
                    if (v[i] < minu)
                    {
                        minu = v[i];
                        mini = i;
                    }
                }
            }

            vector<int> vv;
            for (int i = 0; i < sz(v); ++i)
            {
                if (i == mini)
                    continue;
                vv.push_back(v[i]);
            }
            for (int i = 0; i < 10; ++i)
                vv.push_back(minu / 10);
            v = vv;
        }
    }

    assert(sz(v) == q);
    for (int i = 0; i < q; ++i)
        cout << v[i] << ' ';
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