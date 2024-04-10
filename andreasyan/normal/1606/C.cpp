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
const int N = 12;

int n, k;
int a[N];

void solv()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    ++k;

    int q = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        int x = 0;
        for (int j = 0; j < a[i + 1] - a[i]; ++j)
            x = (x * 10 + 9);

        if (k > x)
        {
            q += (a[i + 1] - a[i]);
            k -= x;
        }
        else
        {
            cout << k;
            for (int i = 0; i < q; ++i)
                cout << '9';
            cout << '\n';
            return;
        }
    }

    cout << k;
    for (int i = 0; i < q; ++i)
        cout << '9';
    cout << '\n';
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
        solv();
    return 0;
}