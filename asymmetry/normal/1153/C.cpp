#include <bits/stdc++.h>

using namespace std;

int n, akt;
int t[300011];
int p[300011];
int g[300011];
char s[300011];

int main()
{
    scanf("%d", &n);
    if(n&1)
    {
        printf(":(");
        return 0;
    }
    scanf("%s", s);
    for(int i=0; i<n; ++i)
    {
        if(s[i]=='(')
        {
            t[i+1]=1;
        }
        else
        {
            if(s[i]==')')
            {
                t[i+1]=-1;
            }
            else
            {
                g[i+1]=1;
            }
        }
    }
    for(int i=n; i>0; --i)
    {
        p[i]=p[i+1]+t[i];
        g[i]+=g[i+1];
    }
    /*for(int i=1; i<=n; ++i)
    {
        printf("%d ", g[i]);
    }
    printf("\n");
    for(int i=1; i<=n; ++i)
    {
        printf("%d ", p[i]);
    }
    printf("\n");*/
    for(int i=1; i<=n; ++i)
    {
        if(!t[i])
        {
            if(akt+p[i+1]<=g[i+1])
            {
                t[i]=1;
            }
            else
            {
                t[i]=-1;
            }
        }
        akt+=t[i];
        if(akt<1 && i<n)
        {
            printf(":(");
            return 0;
        }
    }
    if(akt!=0)
    {
        printf(":(");
        return 0;
    }
    for(int i=1; i<=n; ++i)
    {
        if(t[i]==1)
        {
            printf("(");
        }
        else
        {
            printf(")");
        }
    }
    return 0;
}