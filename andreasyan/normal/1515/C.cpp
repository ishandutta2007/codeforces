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
const int N = 100005;

int n, m, x;
int a[N];

void solv()
{
    cin >> n >> m >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    set<pair<int, int> > s;
    for (int i = 1; i <= m; ++i)
        s.insert(m_p(0, i));

    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
    {
        pair<int, int> u = *s.begin();
        s.erase(s.begin());

        cout << u.se << ' ';

        u.fi += a[i];
        s.insert(u);
    }
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