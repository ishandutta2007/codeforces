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
int pos[105];
int pos2[105];
int cmp(int n,int m){return a[n]<a[m];}
int cmp2(int n,int m){return (b[n]+bb[n])!=(b[m]+bb[m])?((b[n]+bb[n])>(b[m]+bb[m])):(bb[n]>bb[m]);}
int main()
{
    int n,r;
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
            printf("NO\n");
            return 0;
        }
        r+=aa[pos[i]];
    }
    for(int i=0;i<102;i++)pos2[i]=i;
    sort(pos2,pos2+bn,cmp2);//b[pos2[i]],bb[pos2[i]]

    //for(int i=0;i<bn;i++)cout<<pos2[i]<<endl;
    for(int i=0;i<bn;i++)
    {
        if(r<b[pos2[i]])
        {
            printf("NO\n");
            return 0;
        }
        r+=bb[pos2[i]];
    }
    if(r<0)printf("NO\n");
    else printf("YES\n");
    return 0;
}
/*

*/