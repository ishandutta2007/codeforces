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
const int V=100100;
int a[V];
int pt[100],n;
int main()
{
    pt[0]=1;
    for(int i=1;i<=60;i++)
    pt[i]=pt[i-1]*2;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        int id=-1,t=0;
        for(int j=29;j>=0;j--)
        {
            int tmp=-1;
            t=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]&pt[j])
                {
                    if(tmp==-1)tmp=a[i];
                    else tmp&=a[i];
                    t++;
                }
            }
            if(tmp!=-1&&(tmp%pt[j]==0))
            {
                id=j;break;
            }
        }
        printf("%d\n",t);
        for(int i=0;i<n;i++)
        if(a[i]&pt[id])
        printf("%d ",a[i]);
        puts("");
    }
}