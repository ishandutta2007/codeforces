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
const int N = 100005, M = 1000000007;

int n, k;
char a[N];

void solv()
{
    scanf("%d%d", &n, &k);
    scanf(" %s", (a + 1));

    if (n % k != 0)
    {
        printf("-1\n");
        return;
    }

    int q[26] = {};
    for (int i = 1; i <= n; ++i)
        q[a[i] - 'a']++;

    bool z = true;
    for (int j = 0; j < 26; ++j)
    {
        if (q[j] % k != 0)
        {
            z = false;
            break;
        }
    }
    if (z)
    {
        for (int i = 1; i <= n; ++i)
            putchar(a[i]);
        putchar('\n');
        return;
    }
    for (int i = n; i >= 1; --i)
    {
        if (a[i] == 'z')
        {
            q[a[i] - 'a']--;
            continue;
        }
        q[a[i] - 'a']--;
        int p[26] = {};
        for (int j = 0; j < 26; ++j)
        {
            p[j] = (k - (q[j] % k));
            p[j] %= k;
        }
        int s = 0;
        for (int j = 0; j < 26; ++j)
        {
            s += p[j];
        }
        for (int j = a[i] - 'a' + 1; j < 26; ++j)
        {
            s -= p[j];
            p[j] = (p[j] - 1 + k) % k;
            s += p[j];

            if (n - i >= s && (n - i - s) % k == 0)
            {
                for (int k = 1; k < i; ++k)
                    putchar(a[k]);
                putchar(j + 'a');
                for (int k = 0; k < (n - i - s); ++k)
                    putchar('a');
                for (int j = 0; j < 26; ++j)
                {
                    while (p[j]--)
                        putchar(j + 'a');
                }
                putchar('\n');
                return;
            }

            s -= p[j];
            p[j] = (p[j] + 1) % k;
            s += p[j];
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}