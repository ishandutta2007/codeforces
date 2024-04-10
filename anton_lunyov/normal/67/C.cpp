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

#define N 4040

char a[N],b[N];
int f[N][N];
int pa[N][26],pb[N][26];

int main()
{
#ifdef mydebug
	freopen("c.in","r",stdin);
#endif
    int ti,td,tr,te;
    while(scanf("%d%d%d%d",&ti,&td,&tr,&te)>0)
    {
        MIN(tr,ti+td)
            scanf("%s%s",a+1,b+1);
        int n=strlen(a+1);
        int m=strlen(b+1);
        int i,j;
        for(int c=0;c<26;++c)
        {
            int p=0;
            for(i=1;i<=n;++i) 
            {
                pa[i][c]=p;
                if(a[i]-'a'==c) p=i;
            }
            p=0;
            for(i=1;i<=m;++i) 
            {
                pb[i][c]=p;
                if(b[i]-'a'==c) p=i;
            }
        }        
        for(i=0;i<=n;i++)
            for(j=0;j<=m;j++)
                if(i==0) f[i][j]=ti*j; else
                    if(j==0) f[i][j]=td*i; else
                    {
                        int &res=f[i][j];
                        res=min(f[i-1][j]+td,f[i][j-1]+ti);
                        MIN(res,f[i-1][j-1]+tr*(a[i]!=b[j]))
                        int c1=a[i]-'a';
                        int c2=b[j]-'a';
                        int ii=pa[i][c2];
                        int jj=pb[j][c1];
                        if(ii && jj)                        
                            MIN(res,f[ii-1][jj-1]+te+td*(i-ii-1)+ti*(j-jj-1));
                    }
        printf("%d\n",f[n][m]);
    }
    return 0;
}