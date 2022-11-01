#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)1<<19)
#define M ((ll)15)
#define INF ((ll)2e9+100)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

bool dp[N];
vector <ll> line[M];
char c[20];

int main()
{
	line[0]={0,1,2};line[1]={3,4,5,6};line[2]={7,8,9,10,11};line[3]={12,13,14,15};line[4]={16,17,18};
	line[5]={2,6,11};line[6]={1,5,10,15};line[7]={0,4,9,14,18};line[8]={3,8,13,17};line[9]={7,12,16};
	line[10]={11,15,18};line[11]={6,10,14,17};line[12]={2,5,9,13,16};line[13]={1,4,8,12};line[14]={0,3,7};
	dp[0]=1;
	for(int i=1;i<N;i++)
	{
		dp[i]=1;
		for(int j=0;j<M;j++)
			for(int p=0;p<line[j].size();p++)
			{
				ll num=0;
				for(int q=p;q<line[j].size();q++)
				{
					if((i&(1<<line[j][q]))==0)break;
					num+=(1<<line[j][q]);
					if(dp[i-num]==1)dp[i]=0;
				}
			}
	}
	for(int i=0;i<19;i++)cin>>c[i];
	ll x=0;
	for(int i=0;i<20;i++)
		if(c[i]=='O')
			x+=(1<<i);
	cout<<(dp[x]?"Lillebror":"Karlsson");
	return 0;
}