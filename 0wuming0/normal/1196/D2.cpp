#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
using namespace std;
int a[200005],b[200005],c[200005];
char op(int s,int p)
{
    switch(p%3)
    {
        case 0:return s;
        case 1:if(s=='R')return 'B';if(s=='G')return 'R';if(s=='B')return 'G';return s;
        case 2:if(s=='R')return 'G';if(s=='G')return 'B';if(s=='B')return 'R';return s;
    }
}
int main()
{
    int ans;
    char s[200005];
    int i,j,k,t,n;
    scanf("%d",&t);
    while(t--)
    {
        bool flag=0;
        ans=0;
        scanf("%d%d",&n,&k);
        scanf("%s",s);
        if(k==1){if(s[0]=='R'||s[0]=='G'||s[0]=='B')printf("0\n");else printf("1\n");continue;}
        switch(s[0])
        {
            case'R':a[0]=1;b[0]=0;c[0]=0;break;
            case'G':b[0]=1;a[0]=0;c[0]=0;break;
            case'B':c[0]=1;b[0]=0;a[0]=0;break;
            default:a[0]=0;b[0]=0;c[0]=0;break;
        }
        for(i=1;i<n;i++)
        {
            switch(op(s[i],i))
            {
                case'R':a[i]=a[i-1]+1;b[i]=b[i-1];c[i]=c[i-1];break;
                case'G':b[i]=b[i-1]+1;a[i]=a[i-1];c[i]=c[i-1];break;
                case'B':c[i]=c[i-1]+1;b[i]=b[i-1];a[i]=a[i-1];break;
                default:c[i]=c[i-1];b[i]=b[i-1];a[i]=a[i-1];break;
            }
            if(flag)ans=max(max(max(ans,a[i]-a[i-k]),b[i]-b[i-k]),c[i]-c[i-k]);
            if((!flag)&&(i==k-1))
            {
                ans=max(ans,max(max(a[i],b[i]),c[i]));
                flag=1;
            }
        }
        //for(i=0;i<n;i++)printf("%d:%d %d %d\n",i,a[i],b[i],c[i]);
        printf("%d\n",k-ans);
    }
    return 0;
}
/*
3
5 2
BGGGG
5 3
RBRGR
5 5
BBBRR

1
0
3

3
10 5
BRRRRGBRBG
1 1
R
10 5
BRRRRGBRBG
*/