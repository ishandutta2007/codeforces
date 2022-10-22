#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2e6;
const int mo=998244353;
ll dp[N][3];
int a[N],b[N];
ll jc[N],jc2[N];
ll fsp(int x,int y)
{
	if (y==0) return 1;
	if (y==1) return x;
	ll ans=fsp(x,y/2);
	ans=ans*ans%mo;
	if (y%2==1) ans=ans*x%mo;
	return ans; 
}
ll C(int n,int m)
{
	if (n<m) return 0;
	return jc[n]*jc2[m]%mo*jc2[n-m]%mo;
}
int gcd(int x,int y)
{
	if (!y) return x;
	return gcd(y,x%y);
}
const int MN=1e7;
int pri[MN+10],phi[MN+10],cntpri;
bool vispri[MN+10];
inline void prime(){
	phi[1]=1; 
	rep(i,2,MN){
		if(!vispri[i]) { pri[++cntpri]=i; phi[i]=i-1;}
		for(int j=1;j<=cntpri&&i*pri[j]<=MN;++j){
			vispri[i*pri[j]]=1;
			if(i%pri[j]==0)
			{
				phi[i*pri[j]]=phi[i]*pri[j];
			    break;
		    }
		    phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
	}
}

int main()
{
	prime();
	int T;
	cin>>T;
	jc[0]=jc2[0]=1;
	rep(i,1,1e6) jc[i]=jc[i-1]*i%mo;
	jc2[1000000]=fsp(jc[1000000],mo-2);
	dep(i,1e6-1,1) jc2[i]=jc2[i+1]*(i+1)%mo;
	while (T--)
	{
		int n;
		cin>>n;
		rep(i,1,n) cin>>a[i];	
		bool tt=1;
		rep(i,2,n) if (a[i]!=a[i-1]) tt=0;
		if (tt)
		{
			cout<<1<<endl;
			continue;
		}
		sort(a+1,a+n+1);
		int cnt=0;
		rep(i,1,n)
		{ 
		  if (a[i]!=a[i-1])
		  {
			++cnt; b[cnt]=0;
		  }
		  b[cnt]++;
	    }
	    int gg=0;
	    rep(i,1,cnt) gg=gcd(gg,b[i]);
	    ll ans1=0,ans2=0;
	    rep(ii,1,n)
	      	if (gg%ii==0&&n%ii==0)
	        {
	        	int nn=n/ii;
	    		ll ans=1; ll now=0;
			    dp[0][0]=1; dp[0][1]=0; dp[0][2]=0;
			    rep(i,1,cnt)
			    {
			    	ans=ans*C(nn-now,b[i]/ii)%mo;
			    	now+=b[i]/ii;
			    }
			    (ans1+=ans*phi[ii])%=mo;
			    now=0; nn-=2;
			    rep(i,1,cnt)
			    {
			    	dp[i][0]=dp[i-1][0]*C(nn-now,b[i]/ii)%mo;
			    	dp[i][1]=dp[i-1][1]*C(nn-now+1,b[i]/ii)%mo;
			    	dp[i][2]=dp[i-1][2]*C(nn-now+2,b[i]/ii)%mo;
			    	(dp[i][1]+=dp[i-1][0]*C(nn-now,b[i]/ii-1))%=mo;
			    	(dp[i][2]+=dp[i-1][1]*C(nn-now+1,b[i]/ii-1))%=mo;
			    	now+=b[i]/ii;
			    }
			    nn+=2;
			    (ans2+=2*nn%mo*dp[cnt][2]%mo*phi[ii]%mo*ii%mo)%=mo;
			}
		cout<<ans2*fsp(ans1,mo-2)%mo<<endl; 
	}
	return 0;
}