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
const int N = 200005;

int n;
int a[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<int> v;
    bool z = false;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 0)
        {
            if (!z)
            {
                z = true;
                v.push_back(0);
            }
        }
        else
            v.push_back(a[i]);
    }

    if (sz(v) > 5)
    {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < sz(v); ++i)
    {
        for (int j = i + 1; j < sz(v); ++j)
        {
            for (int k = j + 1; k < sz(v); ++k)
            {
                int s = v[i] + v[j] + v[k];
                bool z = false;
                for (int l = 0; l < sz(v); ++l)
                {
                    if (s == v[l])
                    {
                        z = true;
                        break;
                    }
                }
                if (!z)
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
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