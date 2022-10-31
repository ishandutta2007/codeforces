#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=((n&1)?a:1ll),res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=301*1000;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)1e9);

bool mark[100];
ll ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i=2;i<50;i++)
		if(!mark[i])
		{
			printf("%d\n",i);
			fflush(stdout);
			char response[3];
        	scanf("%s", response);
        	if(strcmp(response,"yes")==0)ans++;
        	if(ans>1){printf("composite\n"),fflush(stdout);return 0;}
        	if(i<10)
        	{
	       		printf("%d\n",i*i);
				fflush(stdout);
				char response2[3];
        		scanf("%s", response2);
        		if(strcmp(response2,"yes")==0){printf("composite\n");fflush(stdout);return 0;}
			}
			for(int j=i*i;j<50;j+=i)mark[j]=1;
		}
	printf("prime\n"),fflush(stdout);
  	return 0;
}