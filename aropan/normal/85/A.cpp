#include <cstdio>
#include <map>

using namespace std;

const int MAXN = 1111;

map <int, char> M;

char c1, c2;
int n;
int a[4][MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    scanf("%d", &n);

    int k = 0;

    a[0][0] = a[1][0] = ++k;
    for (int i = 1; i < n; i += 2)
    {
        a[0][i] = a[0][i + 1] = ++k;
        a[1][i] = a[1][i + 1] = ++k;
    }
    for (int i = 0; i < n - 1; i += 2)
    {
        a[2][i] = a[2][i + 1] = ++k;
        a[3][i] = a[3][i + 1] = ++k;
    }

    if (n & 1)
        a[2][n - 1] = a[3][n - 1] = ++k;
    else
        a[0][n - 1] = a[1][n - 1] = ++k;

    c1 = 'a';
    c2 = 'b';
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j && a[i][j] != a[i][j - 1])
                swap(c1, c2);
            if (M[a[i][j]] == 0)
                M[a[i][j]] = c1;

//            printf("%d %d %c %c\n", i, j, c1, c2);
        }
        c1 += 2;
        c2 += 2;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%c", M[a[i][j]]);
        printf("\n");
    }
    return 0;
}