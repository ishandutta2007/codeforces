#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

const int MAXL = 2000;

map <int, int> M;
map <int, int> :: iterator iter;
int n, m, k, x;

int rec(int x)
{
    if (x < k) return 0;
    if (M.find(x) != M.end()) return M[x];

    int a[MAXL];
    int l = 0;

    for (int i = 1; i * i <= x; i++)
        if (x % i == 0)
        {
            int j = x / i;

            if ((1 < i) && (k <= j)) a[l++] = rec(j) * (i & 1);
            if ((1 < j) && (k <= i)) a[l++] = rec(i) & (j & 1);
        }

    sort(a, a + l);
/*
    printf("%d:", x);
    for (int i = 0; i < l; i++)
        printf(" %d", a[i]);
    printf("\n");
//*/
    for (int i = 0, j = 0; true; i++)
    {
        while (j < l && a[j] < i) j++;
        if (j == l || a[j] != i)
            return M[x] = i;
    }
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    scanf("%d %d %d", &n, &m, &k);
    printf("%s\n", (n & 1) && rec(m)? "Timur" : "Marsel");
    return 0;
}