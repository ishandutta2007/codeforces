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

#define bit(n) (1<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))

int main()
{
   // freopen("c.in","r",stdin);
    int a[4];
    while(scanf("%d",a)>0)
    {
        int num=0;
        int i,j;
        for(i=1;i<4;i++) scanf("%d",a+i);
        for(;;)
        {
            for(i=0;i<4 && a[i]==1;i++);
            if(i==4) break;
            for(i=0;i<4;i++)
            {
                j=(i+1)%4;
                if(a[i]%2==0 && a[j]%2==0)
                {
                    a[i]/=2;
                    a[j]/=2;
                    printf("/%d\n",i+1);num++;
                    break;
                }
            }
            if(i<4) continue;
            for(i=0;i<4;i++)
            {
                j=(i+1)%4;
                if(a[i]%2==1 && a[j]%2==1 && a[i]+a[j]>2)
                {
                    a[i]=(a[i]+1)/2;
                    a[j]=(a[j]+1)/2;
                    printf("+%d\n",i+1);num++;
                    printf("/%d\n",i+1);num++;
                    break;
                }
            }
            if(i<4) continue;
            for(i=0;i<4;i++)
            {
                j=(i+1)%4;
                if(a[i]==1 && a[j]==1) break;
            }
            if(i==4) i=0; else i^=2;
            j=(i+1)%4;
            a[i]++;
            a[j]++;
            printf("+%d\n",i+1);num++;
        }
        //printf("%d\n",num);
    }
    return 0;
}