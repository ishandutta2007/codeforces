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
const int N = 18;

int n, r;
int a[(1 << N)];

void solv()
{
    cin >> n >> r;
    for (int x = 0; x < (1 << n); ++x)
        cin >> a[x];

    long double s = 0;
    for (int x = 0; x < (1 << n); ++x)
        s += a[x];

    cout << s / (1 << n) << "\n";
    while (r--)
    {
        int x, y;
        cin >> x >> y;
        s -= a[x];
        a[x] = y;
        s += a[x];
        cout << s / (1 << n) << "\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(9);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}