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
char a[N];
int q[26];

void solv()
{
    cin >> n;
    cin >> a;
    for (int i = 0; i < n; ++i)
        q[a[i] - 'a']++;

    int maxu = 0;
    for (int i = 0; i < 26; ++i)
        maxu = max(maxu, q[i]);

    if (maxu >= 2 || n == 1)
        cout << "Yes\n";
    else
        cout << "No\n";
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
        solv();
    return 0;
}