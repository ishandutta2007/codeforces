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
    int n;
    cin >> n;

    if (n < 1200)
        cout << "1200\n";
    else if (n < 1400)
        cout << "1400\n";
    else if (n < 1600)
        cout << "1600\n";
    else if (n < 1900)
        cout << "1900\n";
    else if (n < 2100)
        cout << "2100\n";
    else if (n < 2300)
        cout << "2300\n";
    else if (n < 2400)
        cout << "2400\n";
    else if (n < 2600)
        cout << "2600\n";
    else
        cout << "3000\n";
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