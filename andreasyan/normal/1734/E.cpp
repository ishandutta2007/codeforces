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
const int N = 355;

int n;
int b[N];

void solv()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    for (int i = 0; i < n; ++i)
    {
        int t = (b[i] - i * i) % n;
        t = (t + n) % n;
        for (int j = 0; j < n; ++j)
        {
            cout << (i * j + t) % n << ' ';
        }
        cout << "\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}