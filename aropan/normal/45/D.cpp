#include <cstdio>
#include <algorithm>
#include <set>

#define L first.second
#define R first.first
#define I second

using namespace std;

const int MAXN = 111;

set <int> S;
int n, m;
pair < pair< int, int >, int > a[MAXN];
int ans[MAXN];

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i].L, &a[i].R);
        a[i].I = i;
    }
    sort(a, a + n);
    
    for (int i = 0; i < n; i++)
        for (int j = a[i].L; j <= a[i].R; j++)
            if (S.find(j) == S.end())
            {
                ans[a[i].I] = j;
                S.insert(j);
                break;
            }
    for (int i = 0; i < n; i++)
    {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}