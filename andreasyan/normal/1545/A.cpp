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

int n;
int a[N];

void solv()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> v[2];
    for (int i = 0; i < n; ++i)
        v[i % 2].push_back(a[i]);
    sort(all(v[0]));
    sort(all(v[1]));
    for (int i = 0; i < n; ++i)
        a[i] = v[i % 2][i / 2];

    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] > a[i + 1])
        {
            cout << "NO\n";
            return;
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