#include <bits/stdc++.h>

using namespace std;

int n, a, g, ugh, b, ugh2;
int t[1001];
int xd[1000];
int dx[1000];
int odp[21][21];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n*n; ++i)
    {
        scanf("%d", &a);
        ++t[a];
    }
    if(n&1)
    {
        a=0;
        b=0;
        for(int i=1; i<=1000; ++i)
        {
            if(t[i]%4==0)
            {
                while(t[i])
                {
                    ++a;
                    xd[a]=i;
                    t[i]-=4;
                }
            }
            else
            {
                if(t[i]%4==3)
                {
                    if(g==0)
                    {
                        g=i;
                        ++b;
                        dx[b]=i;
                        t[i]-=2;
                        while(t[i]>1)
                        {
                            ++a;
                            xd[a]=i;
                            t[i]-=4;
                        }
                    }
                    else
                    {
                        printf("NO\n");
                        return 0;
                    }
                }
                else
                {
                    if(t[i]%4==2)
                    {
                        ++b;
                        dx[b]=i;
                        t[i]-=2;
                        while(t[i])
                        {
                            ++a;
                            xd[a]=i;
                            t[i]-=4;
                        }
                    }
                    else
                    {
                        if(t[i]%4==1)
                        {
                            if(g==0)
                            {
                                g=i;
                                while(t[i]>1)
                                {
                                    ++a;
                                    xd[a]=i;
                                    t[i]-=4;
                                }
                            }
                            else
                            {
                                printf("NO\n");
                                return 0;
                            }
                        }
                    }
                }
            }
        }
        ugh=a;
        ugh2=b;
        a=1;
        for(int i=1; i<=n/2; ++i)
        {
            for(int j=i; j<=n/2; ++j)
            {
                if(a>ugh)
                {
                    printf("NO\n");
                    return 0;
                }
                odp[i][j]=xd[a];
                odp[i][n-j+1]=xd[a];
                odp[n-i+1][j]=xd[a];
                odp[n-i+1][n-j+1]=xd[a];
                ++a;

            }
            for(int j=i+1; j<=n/2; ++j)
            {
                if(a>ugh)
                {
                    printf("NO\n");
                    return 0;
                }
                odp[j][i]=xd[a];
                odp[n-j+1][i]=xd[a];
                odp[j][n-i+1]=xd[a];
                odp[n-j+1][n-i+1]=xd[a];
                ++a;

            }
        }
        b=1;
        for(int i=1; i<=n/2; ++i)
        {
            if(a<=ugh)
            {
                odp[n/2+1][i]=xd[a];
                odp[n/2+1][n-i+1]=xd[a];
                odp[i][n/2+1]=xd[a];
                odp[n-i+1][n/2+1]=xd[a];
                ++a;
            }
            else
            {
                odp[n/2+1][i]=dx[b];
                odp[n/2+1][n-i+1]=dx[b];
                ++b;
                odp[i][n/2+1]=dx[b];
                odp[n-i+1][n/2+1]=dx[b];
                ++b;
            }
        }
        odp[n/2+1][n/2+1]=g;
    }
    else
    {
        a=0;
        for(int i=1; i<=1000; ++i)
        {
            if(t[i]%4!=0)
            {
                printf("NO\n");
                return 0;
            }
            while(t[i])
            {
                ++a;
                xd[a]=i;
                t[i]-=4;
            }
        }
        a=1;
        for(int i=1; i<=n/2; ++i)
        {
            for(int j=i; j<=n/2; ++j)
            {
                odp[i][j]=xd[a];
                odp[i][n-j+1]=xd[a];
                odp[n-i+1][j]=xd[a];
                odp[n-i+1][n-j+1]=xd[a];
                ++a;
            }
            for(int j=i+1; j<=n/2; ++j)
            {
                odp[j][i]=xd[a];
                odp[n-j+1][i]=xd[a];
                odp[j][n-i+1]=xd[a];
                odp[n-j+1][n-i+1]=xd[a];
                ++a;
            }
        }
    }
    printf("YES\n");
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            printf("%d ", odp[i][j]);
        }
        printf("\n");
    }
    return 0;
}