#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=2005;

int n,a[MAXN];
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main()
{
    int cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
    	if(a[i]==1)++cnt;
    }
    if(cnt)return 0*printf("%d\n",n-cnt);
    int ans=n+1;
    for(int i=1;i<=n;i++)
    {
    	int cur=0;
    	for(int j=i;j<=n;j++)
    	{
    		cur=gcd(cur,a[j]);
    		if(cur==1)ans=min(ans,j-i+1);
    	}
    }
    if(ans>n)printf("-1\n");
    else printf("%d\n",ans+n-2);
    return 0;
}