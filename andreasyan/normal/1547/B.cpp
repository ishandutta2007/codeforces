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
const int N = 33;

int n;
char a[N];

void solv()
{
    cin >> a;
    n = strlen(a);

    int l = 0, r = n - 1;

    for (char u = 'a' + n - 1; u >= 'a'; --u)
    {
        if (a[l] == u)
        {
            ++l;
            continue;
        }
        if (a[r] == u)
        {
            --r;
            continue;
        }
        cout << "NO\n";
        return;
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