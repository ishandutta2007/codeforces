#include <stdio.h>
#include <time.h>
#include <assert.h>
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

typedef __int64 LL;
typedef unsigned __int64 ULL;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) {if(a>(b)) a=(b);}
#define MAX(a,b) {if(a<(b)) a=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

#define N 1111

int n,m;
int A[N];
char S[N];
int D[N];

int fnd(int i)
{
    int &res=D[i];
    if(res>=0) return res;
    res=1;
    if(i>0 && S[i-1]=='R') MAX(res,fnd(i-1)+1);
    if(i<m-1 && S[i]=='L') MAX(res,fnd(i+1)+1);
    return res;
}

int main()
{
#ifdef mydebug
	freopen("a.in","r",stdin);
#endif
    int i,j,k;
    for(;scanf("%d",&n)>0;)
    {
        scanf("%s",S);
        for(i=0;i<n;++i) D[i]=-1;
        m=1;
        A[0]=1;
        for(i=0;i<n-1;++i) if(S[i]=='=') ++A[m-1];
        else 
        {
            S[m-1]=S[i];
            A[m++]=1;
        }

        bool f=1;        
        for(i=0;i<m;++i) 
        {
            int r=fnd(i);
            for(j=0;j<A[i];++j) if(f) 
            {
                printf("%d",r);
                f=0;
            }
            else printf(" %d",r);
        }
        printf("\n");
    }
    return 0;
}