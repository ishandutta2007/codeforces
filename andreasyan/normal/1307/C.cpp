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
char s[N];

ll qq[26][26];
ll q[26];

void solv()
{
    scanf(" %s", s);
    n = strlen(s);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            qq[j][s[i] - 'a'] += q[j];
        }
        q[s[i] - 'a']++;
    }

    ll ans = 0;
    for (int j = 0; j < 26; ++j)
        ans = max(ans, q[j]);
    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            ans = max(ans, qq[i][j]);
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}