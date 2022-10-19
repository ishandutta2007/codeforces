#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int a[100006][65],g[65][65],num[130],nn,h[65][65];
int main()
{
    int n;
    ll data;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        for(int j=0;j<63;j++)
        {
            if(data&1ll)a[i][j]=1;
            data>>=1;
        }
    }
    int aa,bb;
    for(int j=0;j<63;j++)
    {
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(a[i][j])
            {
                num[nn]=i,nn++,flag++;
                if(flag==3)
                {
                    cout<<3<<endl;
                    return 0;
                }
            }
        }
    }
    sort(num,num+nn);
    int i,j;
    for(i=1,j=0;i<nn;i++,j++)
    {
        if(num[i]==num[j])
            j--;
        else
            num[j+1]=num[i];
    }
    nn=j+1;
#define pos num
    for(i=0;i<63;i++)
    {
        int r=-1;
        for(j=0;j<nn;j++)
            if(a[pos[j]][i])
            {
                if(r<0)r=j;
                else
                {
                    g[r][j]=g[j][r]=1;
                    break;
                }
            }
    }/*
    for(i=0;i<63;i++)
    {
        for(j=0;j<63;j++)
        {
            if(g[i][j])h[i][h[i][0]+1]=j,h[i][0]++;
        }
    }*/

    for(i=0;i<63;i++)for(j=0;j<63;j++)if(g[i][j]==0)g[i][j]=10000;
    int sum=10000;
    for(int t=1;t<63;t++)
    {
        for(i=0;i<t;i++)for(j=i+1;j<t;j++)
        {
            sum=min(sum,g[i][j]+g[i][t]+g[j][t]);
        }for(int n=0;n<=t;n++)
        for(i=0;i<t;i++)for(j=i+1;j<t;j++)
        {
            g[i][j]=min(g[i][j],g[i][t]+g[j][t]);
        //}
        //for(i=0;i<t;i++)for(j=i+1;j<t;j++)
        //{
            g[i][t]=min(g[i][t],g[i][j]+g[j][t]);
            g[j][t]=min(g[j][t],g[i][j]+g[i][t]);
        }

    }
    if(sum>=10000)sum=-1;
    cout<<sum<<endl;//for(i=0;i<63;i++){for(j=0;j<63;j++)printf("%2d",g[i][j]>=10000?0:g[i][j]);cout<<endl;}
    return 0;
}
/*

*/