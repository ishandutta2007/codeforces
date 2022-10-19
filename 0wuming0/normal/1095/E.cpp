#include"stdio.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
char s[1000006];
int n;
int solve()
{
    int t=0,sum=0,sum0=0,flag=1;//cout<<n<<endl;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')t--;
        else sum++,t++;
        if(t>2)return 0;
        if(t>0&&flag==1)sum0=sum,flag=0;
    }
    return sum0;
}
int main()
{
    while(1)
    {
        if(scanf("%d",&n)==EOF)break;
        scanf("%s",s);
        int a=0,b=0;
        for(int i=0;i<n;i++)if(s[i]=='(')a++;
        else b++;
        if(a==b+2)
        {
            for(int i=0;i<n;i++)if(s[i]=='(')s[i]=')';
            else s[i]='(';
            int i=0,j=n-1;
            for(;i<j;i++,j--)
            {
                swap(s[i],s[j]);
            }
            printf("%d\n",solve());
        }
        else if(a+2==b)
        {
            printf("%d\n",solve());
        }
        else printf("%d\n",0);
    }
    return 0;
}