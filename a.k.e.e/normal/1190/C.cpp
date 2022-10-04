#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005,MOD=998244353;

int n,k;
char s[MAXN];
int pre[2][MAXN],suf[2][MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d%d%s",&n,&k,s+1);
    for(int t=0;t<=1;t++)
    {
    	for(int i=1;i<=n;i++)
    		if(s[i]==t+'0')pre[t][i]=pre[t][i-1]+1;
    		else pre[t][i]=0;
    	for(int i=n;i;i--)
    		if(s[i]==t+'0')suf[t][i]=suf[t][i+1]+1;
    		else suf[t][i]=0;
    	if(pre[t][n]+suf[t][1]+k>=n)return 0*printf("tokitsukaze\n");
    }
    for(int i=1;i<=n-k+1;i++)
    {
    	for(int t=0;t<=1;t++)
    	{
    		int np=i-1+k+suf[t][i+k],ns=n-(i+k-1)+k+pre[t][i-1];
    		if(i>suf[t][1]+1)np=suf[t][1];
    		if(n-(i+k-1)>pre[t][n])ns=pre[t][n];
//cerr<<i<<" "<<t<<" "<<np<<" "<<ns<<endl;
    		if(np+ns+k<n)return 0*printf("once again\n");
    	}
    }
    printf("quailty\n");
    return 0;
}