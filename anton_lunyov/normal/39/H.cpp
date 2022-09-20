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

int k;

void print(int d)
{
    printf("%d",d);
}

int main()
{
    //freopen("in.txt","r",stdin);
    while(scanf("%d",&k)>0)
    {
        int i,j;
        for(i=1;i<k;i++)
            for(j=1;j<k;j++)
            {
                if(i*j<k) print(i*j); else
                    print(i*j/k),print(i*j%k);
                printf("%c",j<k-1?' ':'\n');
            }
    }
    return 0;
}