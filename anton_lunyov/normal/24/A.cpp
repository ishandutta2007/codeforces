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

#define N 111

int A[N][2];
int len[N];
int mark[N];
int p[N];
int plen;

void dfs(int u)
{
    p[plen++]=u;
    mark[u]=1;
    for(int i=0;i<2;i++)
    {
        int v=A[u][i];
        if(!mark[v]) dfs(v);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    int n,i,j;
    while(scanf("%d",&n)>0)
    {
        int u,v,cc;
        int c[N][N]={0};
        fill(len,0);
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&u,&v,&cc);
            c[u][v]=cc;
            A[u][len[u]++]=v;
            A[v][len[v]++]=u;
        }
        plen=0;
        fill(mark,0);
        dfs(1);
        int cur=0;
        for(i=0;i<n;i++)
        {
            int j=(i+1)%n;
            if(!c[p[i]][p[j]]) cur+=c[p[j]][p[i]];
        }
        int ans=cur;
        cur=0;
        for(i=0;i<n;i++)
        {
            int j=(i+n-1)%n;
            if(!c[p[i]][p[j]]) cur+=c[p[j]][p[i]];
        }
        MIN(ans,cur);
        printf("%d\n",ans);
    }
    return 0;
}