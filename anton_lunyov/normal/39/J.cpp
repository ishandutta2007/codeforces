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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef __int64 LL;

#define N 1010101
char a[N],b[N];

int main()
{
   //freopen("in.txt","r",stdin);
    while(scanf("%s%s",a,b)>0)
    {
        int n=strlen(a);
        int i,j,k;
        for(i=0;i<n-1 && a[i]==b[i];i++);
        for(j=n-1;j>0 && a[j]==b[j-1];j--);
        if(i<j) puts("0"); else
        {
            printf("%d\n",i-j+1);
            for(k=j;k<=i;k++)
                printf("%d ",k+1);
            printf("\n");
        }
    }
    return 0;
}