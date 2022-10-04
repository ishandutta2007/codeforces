#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=55;

int n,f[MAXN][MAXN][MAXN][MAXN];
char s[MAXN][MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(int xlen=1;xlen<=n;xlen++)
    	for(int u=1;u+xlen-1<=n;u++)
    		for(int ylen=1,d=u+xlen-1;ylen<=n;ylen++)
    			for(int l=1;l+ylen-1<=n;l++)
    			{
    				int r=l+ylen-1;
    				if(u==d && l==r){f[u][d][l][r]=(s[u][l]=='#');continue;}
    				f[u][d][l][r]=max(xlen,ylen);
    				for(int k=u;k<d;k++)
    					f[u][d][l][r]=min(f[u][d][l][r],f[u][k][l][r]+f[k+1][d][l][r]);
    				for(int k=l;k<r;k++)
    					f[u][d][l][r]=min(f[u][d][l][r],f[u][d][l][k]+f[u][d][k+1][r]);
//cerr<<u<<" "<<d<<" "<<l<<" "<<r<<":"<<f[u][d][l][r]<<endl;
    			}
    printf("%d\n",f[1][n][1][n]);
    return 0;
}