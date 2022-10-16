#include<bits/stdc++.h>
int n,cx[11111],cy[11111];
int cnt[11][11];
int idx[11][11];
int dx[11]={0,0,0,2,2},dy[11]={0,0,2,0,2};
typedef long long ll;
ll C(ll n,ll r)
{
	ll rt=1;
	for(register int i=1;i<=r;i++)
		rt=rt*1ll*(n-i+1)/i;
	return rt;
}
inline int gcd(int x,int y)
{
	int r=y;
	for(;r;r=x%y,x=y,y=r);
	return x<0?-x:x;
}
int A(int x,int y)
{
	return dx[x]*dy[y]-dx[y]*dy[x]-gcd(dx[x]-dx[y],dy[x]-dy[y]);
}
bool check(int x,int y,int z)
{
	return (A(x,y)+A(x,z)+A(y,z))%4==0;
}
int main()
{
	scanf("%d",&n);
	register int i,x,y,z;
	for(i=1;i<=n;i++)scanf("%d%d",cx+i,cy+i),cx[i]%=4,cy[i]%=4,cnt[cx[i]][cy[i]]++;
	idx[0][0]=1,idx[0][2]=2,idx[2][0]=3,idx[2][2]=4;
	ll ans=0;
	for(x=1;x<5;x++)for(y=x;y<5;y++)for(z=y;z<5;z++)
	{
		if(!check(x,y,z))continue;
		if(x==y)
		{
			if(y==z)ans+=C(cnt[dx[x]][dy[x]],3);
			else ans+=C(cnt[dx[x]][dy[x]],2)*cnt[dx[z]][dy[z]];
		}
		else if(y==z)ans+=C(cnt[dx[z]][dy[z]],2)*cnt[dx[x]][dy[x]];
		else ans+=cnt[dx[x]][dy[x]]*1ll*cnt[dx[y]][dy[y]]*cnt[dx[z]][dy[z]];
	}
	printf("%lld\n",ans);
}
// S = V + E/2 - 1 (is Integer) 

// sum (S - E/2) is even

// 2S = 2V + E - 2 => E is even

//