#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;
int a[2][10005];

bool comp(int a, int b)
{
    return a > b;
}

int main()
{
    //freopen("D.out", "w", stdout);
    
    scanf("%d %d\n", &n, &k);
    
    for (int i = 0; i < n-1; i++)
    {
        a[0][i] = 1;
    }
    a[0][n-1] = 0;
    
    for (int step = 1; step <= k; step++)
    {
        for (int i = 0; i < n; i++)
        {
            int *v = lower_bound(a[!(step%2)], a[!(step%2)]+n,
                (n-1-i) - a[!(step%2)][i], comp);
            if (*v > (n-1-i) - a[!(step%2)][i])
            {
                v++;
            }
            
            a[step%2][i] = a[!(step%2)][i] + *v;
            if (i) 
                printf(" ");
            printf("%d", int(v - a[!(step%2)] + 1));
           //printf("%d", a[step%2][i]);
        }
        printf("\n");
    }
}