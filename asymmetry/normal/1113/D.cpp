#include <bits/stdc++.h>

using namespace std;

int n, g, p, k, l;
int t[5001];
int d[5001];
int h[5001];
string s;

int main()
{
    cin>>s;
    n=s.size();
    for(int i=0; i<n; ++i)
    {
        t[i+1]=int(s[i]);
    }
    for(int i=1; i<=n; ++i)
    {
        l=0;
        for(int j=i+1; j<=n; ++j)
        {
            ++l;
            d[l]=t[j];
        }
        for(int j=1; j<=i; ++j)
        {
            ++l;
            d[l]=t[j];
        }
        g=0;
        for(int j=1; j<=n; ++j)
        {
            if(t[j]!=d[j])
            {
                g=1;
            }
        }
        if(g==1)
        {
            for(int j=1; j<=n; ++j)
            {
                h[j]=d[j];
            }
            reverse(h+1, h+1+n);
            g=0;
            for(int j=1; j<=n; ++j)
            {
                if(h[j]!=d[j])
                {
                    g=1;
                }
            }
            if(g==0)
            {
                printf("1");
                return 0;
            }
        }
    }
    if(n&1)
    {
        for(int i=1; i<=n/2; ++i)
        {
            l=0;
            for(int j=n-i+1; j<=n; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            for(int j=i+1; j<=n-i; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            for(int j=1; j<=i; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            g=0;
            for(int j=1; j<=n; ++j)
            {
                if(t[j]!=d[j])
                {
                    g=1;
                }
            }
            if(g==1)
            {
                for(int j=1; j<=n; ++j)
                {
                    h[j]=d[j];
                }
                reverse(h+1, h+1+n);
                g=0;
                for(int j=1; j<=n; ++j)
                {
                    if(h[j]!=d[j])
                    {
                        g=1;
                    }
                }
                if(g==0)
                {
                    printf("2");
                    return 0;
                }
            }
            l=0;
            for(int j=n-i+1; j<=n; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            for(int j=1; j<=i; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            for(int j=i+1; j<=n-i; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            g=0;
            for(int j=1; j<=n; ++j)
            {
                if(t[j]!=d[j])
                {
                    g=1;
                }
            }
            if(g==1)
            {
                for(int j=1; j<=n; ++j)
                {
                    h[j]=d[j];
                }
                reverse(h+1, h+1+n);
                g=0;
                for(int j=1; j<=n; ++j)
                {
                    if(h[j]!=d[j])
                    {
                        g=1;
                    }
                }
                if(g==0)
                {
                    printf("2");
                    return 0;
                }
            }
            l=0;
            for(int j=1; j<=i; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            for(int j=n-i+1; j<=n; ++j)
            {
                ++l;
                d[l]=t[j];
            }

            for(int j=i+1; j<=n-i; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            g=0;
            for(int j=1; j<=n; ++j)
            {
                if(t[j]!=d[j])
                {
                    g=1;
                }
            }
            if(g==1)
            {
                for(int j=1; j<=n; ++j)
                {
                    h[j]=d[j];
                }
                reverse(h+1, h+1+n);
                g=0;
                for(int j=1; j<=n; ++j)
                {
                    if(h[j]!=d[j])
                    {
                        g=1;
                    }
                }
                if(g==0)
                {
                    printf("2");
                    return 0;
                }
            }
            l=0;
            for(int j=1; j<=i; ++j)
            {
                ++l;
                d[l]=t[j];
            }


            for(int j=i+1; j<=n-i; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            for(int j=n-i+1; j<=n; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            g=0;
            for(int j=1; j<=n; ++j)
            {
                if(t[j]!=d[j])
                {
                    g=1;
                }
            }
            if(g==1)
            {
                for(int j=1; j<=n; ++j)
                {
                    h[j]=d[j];
                }
                reverse(h+1, h+1+n);
                g=0;
                for(int j=1; j<=n; ++j)
                {
                    if(h[j]!=d[j])
                    {
                        g=1;
                    }
                }
                if(g==0)
                {
                    printf("2");
                    return 0;
                }
            }
            l=0;
            for(int j=i+1; j<=n-i; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            for(int j=n-i+1; j<=n; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            for(int j=1; j<=i; ++j)
            {
                ++l;
                d[l]=t[j];
            }

            g=0;
            for(int j=1; j<=n; ++j)
            {
                if(t[j]!=d[j])
                {
                    g=1;
                }
            }
            if(g==1)
            {
                for(int j=1; j<=n; ++j)
                {
                    h[j]=d[j];
                }
                reverse(h+1, h+1+n);
                g=0;
                for(int j=1; j<=n; ++j)
                {
                    if(h[j]!=d[j])
                    {
                        g=1;
                    }
                }
                if(g==0)
                {
                    printf("2");
                    return 0;
                }
            }
            l=0;
            for(int j=i+1; j<=n-i; ++j)
            {
                ++l;
                d[l]=t[j];
            }

            for(int j=1; j<=i; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            for(int j=n-i+1; j<=n; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            g=0;
            for(int j=1; j<=n; ++j)
            {
                if(t[j]!=d[j])
                {
                    g=1;
                }
            }
            if(g==1)
            {
                for(int j=1; j<=n; ++j)
                {
                    h[j]=d[j];
                }
                reverse(h+1, h+1+n);
                g=0;
                for(int j=1; j<=n; ++j)
                {
                    if(h[j]!=d[j])
                    {
                        g=1;
                    }
                }
                if(g==0)
                {
                    printf("2");
                    return 0;
                }
            }
        }
    }
    else
    {
        for(int i=1; i<n/2; ++i)
        {
            l=0;
            for(int j=n-i+1; j<=n; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            for(int j=i+1; j<=n-i; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            for(int j=1; j<=i; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            g=0;
            for(int j=1; j<=n; ++j)
            {
                if(t[j]!=d[j])
                {
                    g=1;
                }
            }
            if(g==1)
            {
                for(int j=1; j<=n; ++j)
                {
                    h[j]=d[j];
                }
                reverse(h+1, h+1+n);
                g=0;
                for(int j=1; j<=n; ++j)
                {
                    if(h[j]!=d[j])
                    {
                        g=1;
                    }
                }
                if(g==0)
                {
                    printf("2");
                    return 0;
                }
            }
            l=0;
            for(int j=n-i+1; j<=n; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            for(int j=1; j<=i; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            for(int j=i+1; j<=n-i; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            g=0;
            for(int j=1; j<=n; ++j)
            {
                if(t[j]!=d[j])
                {
                    g=1;
                }
            }
            if(g==1)
            {
                for(int j=1; j<=n; ++j)
                {
                    h[j]=d[j];
                }
                reverse(h+1, h+1+n);
                g=0;
                for(int j=1; j<=n; ++j)
                {
                    if(h[j]!=d[j])
                    {
                        g=1;
                    }
                }
                if(g==0)
                {
                    printf("2");
                    return 0;
                }
            }
            l=0;
            for(int j=1; j<=i; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            for(int j=n-i+1; j<=n; ++j)
            {
                ++l;
                d[l]=t[j];
            }

            for(int j=i+1; j<=n-i; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            g=0;
            for(int j=1; j<=n; ++j)
            {
                if(t[j]!=d[j])
                {
                    g=1;
                }
            }
            if(g==1)
            {
                for(int j=1; j<=n; ++j)
                {
                    h[j]=d[j];
                }
                reverse(h+1, h+1+n);
                g=0;
                for(int j=1; j<=n; ++j)
                {
                    if(h[j]!=d[j])
                    {
                        g=1;
                    }
                }
                if(g==0)
                {
                    printf("2");
                    return 0;
                }
            }
            l=0;
            for(int j=1; j<=i; ++j)
            {
                ++l;
                d[l]=t[j];
            }


            for(int j=i+1; j<=n-i; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            for(int j=n-i+1; j<=n; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            g=0;
            for(int j=1; j<=n; ++j)
            {
                if(t[j]!=d[j])
                {
                    g=1;
                }
            }
            if(g==1)
            {
                for(int j=1; j<=n; ++j)
                {
                    h[j]=d[j];
                }
                reverse(h+1, h+1+n);
                g=0;
                for(int j=1; j<=n; ++j)
                {
                    if(h[j]!=d[j])
                    {
                        g=1;
                    }
                }
                if(g==0)
                {
                    printf("2");
                    return 0;
                }
            }
            l=0;
            for(int j=i+1; j<=n-i; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            for(int j=n-i+1; j<=n; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            for(int j=1; j<=i; ++j)
            {
                ++l;
                d[l]=t[j];
            }

            g=0;
            for(int j=1; j<=n; ++j)
            {
                if(t[j]!=d[j])
                {
                    g=1;
                }
            }
            if(g==1)
            {
                for(int j=1; j<=n; ++j)
                {
                    h[j]=d[j];
                }
                reverse(h+1, h+1+n);
                g=0;
                for(int j=1; j<=n; ++j)
                {
                    if(h[j]!=d[j])
                    {
                        g=1;
                    }
                }
                if(g==0)
                {
                    printf("2");
                    return 0;
                }
            }
            l=0;
            for(int j=i+1; j<=n-i; ++j)
            {
                ++l;
                d[l]=t[j];
            }

            for(int j=1; j<=i; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            for(int j=n-i+1; j<=n; ++j)
            {
                ++l;
                d[l]=t[j];
            }
            g=0;
            for(int j=1; j<=n; ++j)
            {
                if(t[j]!=d[j])
                {
                    g=1;
                }
            }
            if(g==1)
            {
                for(int j=1; j<=n; ++j)
                {
                    h[j]=d[j];
                }
                reverse(h+1, h+1+n);
                g=0;
                for(int j=1; j<=n; ++j)
                {
                    if(h[j]!=d[j])
                    {
                        g=1;
                    }
                }
                if(g==0)
                {
                    printf("2");
                    return 0;
                }
            }
        }
    }
    printf("Impossible");
    return 0;
}