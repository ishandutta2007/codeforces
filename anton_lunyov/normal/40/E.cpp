#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;

#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define X first
#define Y second
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))

int powmod(int a,int n,int mod)
{
    int p=1;
    for(;n;)
    {
        if(n%2) p=LL(p)*a%mod;
        if(n/=2) a=LL(a)*a%mod;
    }
    return p;
}

#define N 1111

int main()
{
   // freopen("e.in","r",stdin);
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)>0)
    {
        int x[N],y[N],v[N];
        int i,j;
        for(i=0;i<k;i++)
            scanf("%d%d%d",x+i,y+i,v+i);
        int p;
        scanf("%d",&p);
        if((n+m)%2){puts("0");continue;}
        if(n<m)
        {
            swap(n,m);
            for(i=0;i<k;i++)
                swap(x[i],y[i]);
        }
        //n>=m
        int num[N]={0};
        int prod[N];
        for(i=0;i<n;i++) prod[i]=1;
        for(i=0;i<k;i++)
        {
            x[i]--;
            num[x[i]]++;
            prod[x[i]]*=v[i];
        }
        bool flag=0;
        int ans=1;
        for(i=0;i<n;i++)
        {
            if(num[i]==0)
            {
                if(!flag)
                {
                    flag=true;
                    continue;
                }
            }
            if(num[i]==m)
            {
                if(prod[i]!=-1) ans=0;
            }
            else
            {
                ans=LL(ans)*powmod(2,m-num[i]-1,p)%p;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}