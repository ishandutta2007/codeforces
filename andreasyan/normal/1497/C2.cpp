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

void solv()
{
    int n, k;
    cin >> n >> k;

    while (k > 3)
    {
        cout << 1 << ' ';
        --k;
        --n;
    }

    if (n % 2 == 1)
        cout << n / 2 << ' ' << n / 2 << ' ' << 1 << "\n";
    else
    {
        if ((n / 2) % 2 == 0)
            cout << n / 4 << ' ' << n / 4 << ' ' << n / 2 << "\n";
        else
            cout << (n - 2) / 2 << ' ' << (n - 2) / 2 << ' ' << 2 << "\n";
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
    //scanf("%d", &tt);
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}