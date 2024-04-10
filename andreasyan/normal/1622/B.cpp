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

struct ban
{
    int i;
    int x, y;
};
bool operator<(const ban& a, const ban& b)
{
    return m_p(a.x, a.y) < m_p(b.x, b.y);
}

int n;
ban a[N];
char b[N];

int ans[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].y;
    cin >> (b + 1);
    for (int i = 1; i <= n; ++i)
        a[i].x = b[i] - '0';
    for (int i = 1; i <= n; ++i)
        a[i].i = i;

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; ++i)
        ans[a[i].i] = i;

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
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