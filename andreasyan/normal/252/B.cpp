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
int a[N];
int b[N];

bool stg()
{
    bool z = true;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != b[i])
        {
            z = false;
            break;
        }
    }
    if (z)
        return true;
    z = true;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != b[n - i + 1])
        {
            z = false;
            break;
        }
    }
    if (z)
        return true;
    return false;
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    if (n == 2)
    {
        printf("-1\n");
        return;
    }
    bool z = true;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != a[1])
        {
            z = false;
            break;
        }
    }
    if (z)
    {
        printf("-1\n");
        return;
    }
    int maxu = -1;
    int maxi;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > maxu)
        {
            maxu = a[i];
            maxi = i;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == maxu)
            continue;
        swap(a[i], a[maxi]);
        if (!stg())
        {
            printf("%d %d\n", i, maxi);
            return;
        }
        swap(a[i], a[maxi]);
    }
    int minu = 1000000009, mini;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] < minu)
        {
            minu = a[i];
            mini = i;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == minu)
            continue;
        swap(a[i], a[mini]);
        if (!stg())
        {
            printf("%d %d\n", i, mini);
            return;
        }
        swap(a[i], a[mini]);
    }
    printf("-1\n");
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