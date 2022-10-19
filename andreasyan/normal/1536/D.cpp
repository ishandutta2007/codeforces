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
int b[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    set<int> s;
    s.insert(b[1]);
    s.insert(b[2]);
    for (int i = 3; i <= n; ++i)
    {
        auto it = s.upper_bound(min(b[i], b[i - 1]));
        if (it != s.end())
        {
            if (*it < max(b[i], b[i - 1]))
            {
                cout << "NO\n";
                return;
            }
        }
        s.insert(b[i]);
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