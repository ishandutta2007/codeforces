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

    if (a[n - 1] > a[n])
    {
        cout << "-1\n";
        return;
    }

    int y = n - 1;
    int z = n;

    int maxi;
    if (a[n - 1] > a[n])
        maxi = n - 1;
    else
        maxi = n;
    for (int i = n - 2; i >= 1; --i)
    {
        if (a[i] <= a[i + 1])
        {
            if (a[i] - a[maxi] < a[y] - a[z])
            {
                y = i;
                z = maxi;
            }
            if (a[i] > a[maxi])
                maxi = i;
        }
        else
        {
            if (a[y] - a[z] <= a[i + 1])
            {
                cout << i << "\n";
                for (int x = 1; x <= i; ++x)
                {
                    cout << x << ' ' << y << ' ' << z << "\n";
                }
                return;
            }
            else
            {
                cout << "-1\n";
                return;
            }
        }
    }
    cout << "0\n";
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