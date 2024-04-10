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

bool isprime(int x)
{
    if (x <= 1)
        return false;
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

void solv()
{
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 1; i <= 20; ++i)
    {
        for (int j = i + 1; j <= 20; ++j)
        {
            if (isprime(i) && isprime(j))
                v.push_back(i * j);
        }
    }

    for (int i = 0; i < sz(v); ++i)
    {
        for (int j = i + 1; j < sz(v); ++j)
        {
            for (int k = j + 1; k < sz(v); ++k)
            {
                int u = n - v[i] - v[j] - v[k];
                if (u > 0)
                {
                    if (u != v[i] && u != v[j] && u != v[k])
                    {
                        cout << "YES\n";
                        cout << v[i] << ' ' << v[j] << ' ' << v[k] << ' ' << u << "\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "NO\n";
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