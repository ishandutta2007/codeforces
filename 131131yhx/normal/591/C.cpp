#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 500010

using namespace std;

int a[M], b[M];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    a[0] = a[1];
    a[n + 1] = a[n];
    int ans = 0, lin = 0, last = 1;
    for(int i = 1; i <= n + 1; i++)
    {
        if(a[i] != a[i-1] && a[i] != a[i + 1])
            lin++;
        else
        {
            ans = max(ans, (lin + 1)/ 2);
            if(lin == 0) b[i-1] = a[i-1];
            else
            {
            for(int j = last; j <= last + lin / 2; j++)
                b[j] = a[last - 1];
            for(int j = last + lin / 2 + 1; j < i; j++)
                b[j] = a[i];
            }
            last = i;
            lin = 0;
        }
    }
    printf("%d\n", ans);
    for(int i = 1; i <= n; i++) printf("%d ", b[i]);
    putchar('\n');
    return 0;
}