#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005,MOD=998244353;

int n,x[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i];
    sort(x+1,x+n+1);
    int pos=-1;
    for(int i=2;i<=n;i++)
    	if(x[i]==x[i-1])
		{
			if(pos>=0)return 0*printf("cslnb\n");
			pos=x[i];
		}
	if(pos==0)return 0*printf("cslnb\n");
	for(int i=1;i<=n;i++)
		if(x[i]==pos-1)return 0*printf("cslnb\n");
    int win=(1ll*n*(n-1)/2)&1;
    for(int i=1;i<=n;i++)win^=(x[i]&1);
    printf(win%2?"sjfnb\n":"cslnb\n");
    return 0;
}