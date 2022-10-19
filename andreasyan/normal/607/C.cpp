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
const int N = 2000006;

int n;
char a[N], b[N];

int z[N];

void solv()
{
    scanf("%d", &n);
    --n;
    scanf(" %s %s", a, b);

    reverse(a, a + n);
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 'N')
            a[i] = 'S';
        else if (a[i] == 'S')
            a[i] = 'N';
        else if (a[i] == 'E')
            a[i] = 'W';
        else if (a[i] == 'W')
            a[i] = 'E';
    }

    int nn = n;
    for (int i = 0; i < nn; ++i)
        a[n++] = b[i];

    int l = 0, r = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (a[z[i]] == a[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
        {
            r = i + z[i] - 1;
            l = i;
        }
    }

    for (int i = nn; i < n; ++i)
    {
        if (i + z[i] == n)
        {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
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