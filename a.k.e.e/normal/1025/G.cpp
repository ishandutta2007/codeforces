#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=505,MOD=1000000007;

int n,cnt[MAXN];
int qmi(int x,int k)
{
	int ans=1;
	for(;k;k>>=1,x=(ll)x*x%MOD)
		if(k&1)ans=(ll)ans*x%MOD;
	return ans; 
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int x;
    scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x>0)++cnt[x]; 
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(cnt[i])
			ans=(ans+qmi(2,cnt[i])-1)%MOD;
	printf("%d\n",(qmi(2,n-1)-1-ans+MOD)%MOD);
    return 0;
}