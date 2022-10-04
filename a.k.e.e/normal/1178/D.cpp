#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=2005,MOD=998244353;

int n;
bool notp[MAXN];
int prm[MAXN],pn;
void getprime(int n)
{
	notp[0]=notp[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!notp[i])prm[++pn]=i;
		for(int j=1;j<=pn && i*prm[j]<=n;j++)
		{
			notp[i*prm[j]]=1;
			if(!(i%prm[j]))break;
		}
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n;
    getprime(2*n);
    int u=lower_bound(prm+1,prm+pn+1,n)-prm;
    u=prm[u];
    printf("%d\n",u);
    for(int i=1;i<n;i++)printf("%d %d\n",i,i+1);
    printf("%d 1\n",n);
    for(int i=1;i<=u-n;i++)printf("%d %d\n",i,i+n/2);
    return 0;
}