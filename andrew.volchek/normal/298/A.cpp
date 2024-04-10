#include <cstdio>


int a[1111];
int lcnt = 0;
int rcnt = 0;
int n;

int main()
{
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
    {
        char c;
        scanf("%c", &c);
        if (c=='.')
        {
            a[i] = 0;
        }
        else if(c=='L')
        {
            a[i] = 1;
            lcnt++;
        }
        else
        {
            a[i] = 2;
            rcnt++;
        }
    }
    a[n+1] = 0;
    
    if (lcnt && rcnt)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 2)
            {
                int j = i+1;
                while (a[j] == 2)j++;
                printf("%d %d", i, j-1); 
                return 0;
            }
        }
    }
    else if (lcnt)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 1)
            {
                int j = i+1;
                while (a[j] == 1)j++;
                printf("%d %d", j-1, i-1); 
                return 0;
            }
        }
    }
    else 
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 2)
            {
                int j = i+1;
                while (a[j] == 2)j++;
                printf("%d %d", i, j); 
                return 0;
            }
        }
    }
    return 0;
}