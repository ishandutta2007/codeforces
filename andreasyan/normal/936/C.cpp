#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 2003;

int n;
char a[N], b[N];
char aa[N], bb[N];

vector<int> ans;
void ubd(int x)
{
    ans.push_back(x);
    int z = 0;
    for (int i = n; i >= n - x + 1; --i)
        aa[++z] = a[i];
    for (int i = 1; i < n - x + 1; ++i)
        aa[++z] = a[i];
    for (int i = 1; i <= n; ++i)
        a[i] = aa[i];
}

void solv()
{
    scanf("%d", &n);
    scanf(" %s", (a + 1));
    scanf(" %s", (b + 1));
    for (int i = 1; i <= n; ++i)
    {
        aa[i] = a[i];
        bb[i] = b[i];
    }
    sort(aa + 1, aa + n + 1);
    sort(bb + 1, bb + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (aa[i] != bb[i])
        {
            printf("-1\n");
            return;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        int x;
        for (int j = 1; j <= n - i + 1; ++j)
        {
            if (a[j] == b[i])
            {
                x = j;
                break;
            }
        }
        ubd(n - x);
        ubd(1);
        ubd(n);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return;
    for (int i = 1; i <= n; ++i)
        printf("%c", a[i]);
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