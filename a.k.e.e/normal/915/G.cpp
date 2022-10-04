#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
#define pb push_back
const int MAXN=2000005,MOD=1000000007;

int n,k;
int qmi(int x,int k)
{
	int ans=1;
	for(;k;k>>=1,x=(ll)x*x%MOD)
		if(k&1)ans=(ll)ans*x%MOD;
	return ans;
}
int nmi[MAXN];
int prm[MAXN],mu[MAXN],pn;
bool notp[MAXN];
void table(int n)
{
	notp[0]=notp[1]=1;
	mu[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!notp[i]){notp[i]=1;mu[i]=-1;prm[++pn]=i;}
		for(int j=1;prm[j]*i<=n;j++)
		{
			notp[prm[j]*i]=1;
			if(i%prm[j])mu[prm[j]*i]=-mu[i];
			else{mu[prm[j]*i]=0;break;}
		}
	}
}

vector<int> G[MAXN];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
    {
    	nmi[i]=qmi(i,n);
    	for(int j=i;j<=k;j+=i)
    		G[j].pb(i);
    }
    table(k);
    ll ans=0,cur=0;
    for(int i=1;i<=k;i++)
    {
    	for(int j=0;j<G[i].size();j++)
    		cur=(cur+(nmi[i/G[i][j]]-nmi[i/G[i][j]-1])*mu[G[i][j]]+4ll*MOD)%MOD;
    	ans=(ans+(cur^i))%MOD;
    }
    cout<<ans<<endl;
    return 0;
}