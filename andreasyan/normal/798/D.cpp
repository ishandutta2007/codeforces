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
struct ban
{
    int i;
    int a, b;
};
bool operator<(const ban& a, const ban& b)
{
    return a.a < b.a;
}

int n;
ban a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i].a);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i].b);
    for (int i = 1; i <= n; ++i)
        a[i].i = i;
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    printf("%d\n", n / 2 + 1);
    int s;
    if (n % 2 == 1)
    {
        printf("%d ", a[1].i);
        s = 2;
    }
    else
    {
        printf("%d %d ", a[1].i, a[2].i);
        s = 3;
    }
    for (int i = s; i <= n; i += 2)
    {
        if (a[i].b > a[i + 1].b)
            printf("%d ", a[i].i);
        else
            printf("%d ", a[i + 1].i);
    }
    printf("\n");
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