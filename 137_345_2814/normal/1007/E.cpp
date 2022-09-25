//I don't understand
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 204
#define ll long long
int n,t,k,fi[N],gi[N];
ll dp[N][N],as=1e18,f1[N],s[N][3],fr[N];
int main()
{
	scanf("%d%d%d",&n,&t,&k);
	for(int i=1;i<=n;i++)for(int j=0;j<3;j++)scanf("%d",&s[i][j]);
	s[++n][0]=1e14;s[n][1]=0;s[n][2]=1e15;
	gi[0]=fi[0]=t+1;
	for(int i=0;i<t;i++)dp[0][i]=1e18,f1[i]=1e18;
	for(int i=1;i<=n;i++)for(int j=0;j<=t;j++)dp[i][j]=1e18;
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=t;l++)fr[l]=-1;
		fr[0]=0;
		ll si=0;
		for(int j=1;j<=i;j++)si+=s[j][1];
		for(int j=0;j<=t;j++)if(fr[j]>=0)
		for(int l=1;j+l<=t&&l<=gi[i-1];l++)
		{
			ll rs=fr[j]+l*s[i][1],r2=l*(si-s[i][1]);
			if(fr[j]-fr[j]/k*k+l*s[i][1]>s[i][2])continue;
			rs=rs+r2-(r2+k-1)/k*k;
			if(rs>s[i][2])rs-=(rs-s[i][2]+k-1)/k*k;
			fr[j+l]=max(fr[j+l],rs);
		}
		for(int j=0;j<=t;j++)if(fr[j]>=0)gi[i]=max(1ll*gi[i],min(1ll*t+1,j+min(1ll*gi[i-1],s[i][1]?(s[i][2]-fr[j]+fr[j]/k*k)/s[i][1]:10000ll)));
		for(int j=0;j<=t;j++)
		{
			f1[j]=1e18;
			for(int l=i-1;l>=0;l--)
			{
				f1[j]=min(f1[j],dp[l][j]);
				if(s[l][1]*(t-j)>s[l][2])break;
			}
		}
		for(int j=0;j<=t;j++)for(int l=j+1;l<=t;l++)if(fr[l-j]>=0)
		{
			ll su=si*(l-j),s1=fr[l-j];
			if(s1+(t-l)*s[i][1]>s[i][2])s1-=(s1+(t-l)*s[i][1]-s[i][2]+k-1)/k*k;
			if(s1<0)continue;
			dp[i][j]=min(dp[i][j],f1[l]+(su-s1)/k);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i][0]+s[i][1]*t>s[i][2])as=1e18;
		for(int l=0;l<=t;l++)fr[l]=-1;
		ll si=0,sr=0;
		for(int j=1;j<=i;j++)si+=s[j][1],sr+=s[j][0];
		for(int j=0;j<=fi[i-1];j++)
		{
			ll rs=s[i][0]+j*s[i][1],r2=si*j+sr-rs;
			if(rs>s[i][2])continue;
			rs=rs+r2-(r2+k-1)/k*k;
			if(rs>s[i][2])rs-=(rs-s[i][2]+k-1)/k*k;
			fr[j]=max(fr[j],rs);
		}
		for(int j=0;j<=t;j++)if(fr[j]>=0)
		for(int l=1;j+l<=t&&l<=gi[i-1];l++)
		{
			ll rs=fr[j]+l*s[i][1],r2=l*(si-s[i][1]);
			if(fr[j]+l*s[i][1]-fr[j]/k*k>s[i][2])continue;
			rs=rs+r2-(r2+k-1)/k*k;
			if(rs>s[i][2])rs-=(rs-s[i][2]+k-1)/k*k;
			fr[j+l]=max(fr[j+l],rs);
		}
		for(int j=0;j<=t;j++)if(fr[j]>=0)fi[i]=max(1ll*fi[i],min(1ll*t+1,j+min(1ll*gi[i-1],s[i][1]?(s[i][2]-fr[j]+fr[j]/k*k)/s[i][1]:10000ll)));
		for(int l=0;l<=t;l++)if(fr[l]>=0)
		{
			ll su=si*l+sr,s1=fr[l];
			if(s1+(t-l)*s[i][1]>s[i][2])s1-=(s1+(t-l)*s[i][1]-s[i][2]+k-1)/k*k;
			if(s1<0)continue;
			for(int j=i-1;j>=0;j--)
			{
				as=min(as,dp[j][l]+(su-s1)/k);
				if(s[j][1]*(t-l)>s[j][2])break;
			}
		}
		
	}
	printf("%lld\n",as);
}