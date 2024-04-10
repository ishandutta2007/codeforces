#include<bits/stdc++.h>
using namespace std;
int N;
int a[10];
int b[10];
int c[10];
int main()
{
    scanf("%d", &N);
    for(int i=0;i<N; ++i)
    {
        int t; 
        scanf("%1d", &t);
        a[t]++;
    }
    for(int i=0;i<N; ++i)
    {
        int t; 
        scanf("%1d", &t);
        b[t]++;
        c[t]++;
    }
    int ans0=0, ans1=0;
    for(int i=0; i<N; ++i)
    {
        int nexti=0;
        for(int j=0; j<10; ++j)
        {
            if(a[j])
            {
                nexti = j;
                break;
            }
        }
        
        a[nexti]--;
        int j;
        for(j=nexti; j<10; ++j)
        {
            if(b[j])
            {
                b[j]--;
                break;
            }
        }
        if(j==10) ans0++;
        
        for(j=nexti+1; j<10; ++j)
        {
            if(c[j])
            {
                c[j]--;
                break;
            }
        }
        if(j!=10) ans1++;
    }
    printf("%d\n%d\n",ans0,ans1);
}