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
    sort(a + 1, a + n + 1);

    ll sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += a[i];
    priority_queue<ll> q;
    q.push(sum);
    for (int i = n; i >= 1; --i)
    {
        while (q.top() > a[i])
        {
            if (sz(q) > n)
            {
                cout << "NO\n";
                return;
            }
            ll x = q.top();
            q.pop();
            q.push(x / 2);
            q.push(x / 2 + x % 2);
        }
        if (q.top() != a[i])
        {
            cout << "NO\n";
            return;
        }
        q.pop();
    }
    assert(q.empty());
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