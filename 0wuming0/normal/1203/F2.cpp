#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int a[105],aa[105],an;
int b[105],bb[105],bn;
int c[105],cc[105],cn;
int pos[105];
int pos2[105];
int cmp(int n,int m){return a[n]<a[m];}
int cmp2(int n,int m){return (b[n]+bb[n])!=(b[m]+bb[m])?((b[n]+bb[n])>(b[m]+bb[m])):(bb[n]>bb[m]);}
int main()
{
    int n,r,sum=0;
    cin>>n>>r;
    for(int i=0;i<n;i++)
    {
        int p,q;
        scanf("%d%d",&p,&q);
        if(q<0)
        {
            b[bn]=p;
            bb[bn]=q;
            bn++;
        }
        else
        {
            a[an]=p;
            aa[an]=q;
            an++;
        }
    }
    for(int i=0;i<102;i++)pos[i]=i;
    sort(pos,pos+an,cmp);//a[pos[i]],aa[pos[i]]
    //for(int i=0;i<an;i++)cout<<pos[i]<<endl;
    for(int i=0;i<an;i++)
    {
        if(r<a[pos[i]])
        {
            break;
        }
        sum++;
        r+=aa[pos[i]];
    }
    for(int i=0;i<102;i++)pos2[i]=i;
    sort(pos2,pos2+bn,cmp2);//b[pos2[i]],bb[pos2[i]]
    for(int i=0;i<bn;i++)c[i]=b[pos2[i]],cc[i]=bb[pos2[i]];

    int rr[105]={0};
    memset(rr,-1,4*103);
    rr[0]=r;
    for(int i=0;i<bn;i++)
    {
        for(int j=i+1;j>0;j--)
            if(rr[j-1]>=b[pos2[i]])
                rr[j]=max(rr[j],rr[j-1]+bb[pos2[i]]);
    }
    int all=0;
    while(rr[all]>=0)all++;
    printf("%d\n",sum+all-1);
    return 0;
}
/*

*/