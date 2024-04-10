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
char a[N];

void solv()
{
    cin >> n;
    cin >> (a + 1);

    int q = 0;
    for (int i = 1; i <= n * 2; ++i)
        q += (a[i] - '0');
    if (q % 2 == 1)
    {
        cout << "-1\n";
        return;
    }

    vector<int> v;
    for (int i = 1; i <= n * 2; i += 2)
    {
        if (a[i] != a[i + 1])
        {
            if (sz(v) % 2 == 0)
            {
                if (a[i] == '0')
                    v.push_back(i);
                else
                    v.push_back(i + 1);
            }
            else
            {
                if (a[i] == '1')
                    v.push_back(i);
                else
                    v.push_back(i + 1);
            }
        }
    }

    cout << sz(v) << ' ';
    for (int i = 0; i < sz(v); ++i)
        cout << v[i] << ' ';
    cout << "\n";
    for (int i = 1; i <= n * 2; i += 2)
        cout << i << ' ';
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