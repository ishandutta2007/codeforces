#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=1000100;
const int N=1000000;
int a[V],n;
int ret[V],m,x;
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            a[x]=1;
        }
        int pr=0;m=0;
        for(int i=1;i<=N;i++)
        {
            if(a[i]!=1)continue;
            if(a[N+1-i]==1)pr++;
            else
            {
                ret[m++]=N+1-i;
                a[N+1-i]=2;
            }
        }
        for(int i=1;i<=N;i++)
        {
            if(pr==0)break;
            if(a[i]==0&&a[N+1-i]==0)
            {
                ret[m++]=i;
                ret[m++]=N+1-i;
                pr-=2;
            }
        }
        printf("%d\n",m);
        for(int i=0;i<m;i++)
        {
            if(i!=0)printf(" ");
            printf("%d",ret[i]);
        }puts("");
    }
}