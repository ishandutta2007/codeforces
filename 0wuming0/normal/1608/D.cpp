#include<bits/stdc++.h>
#define dbg(x) cout << #x << "===" << x << endl
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;
const int INF = 2e18;
const double PI=acos(-1);
const double eps=1e-7;
int read()
{
    int s=0,bj=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')bj|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
    return bj?-s:s;
}
int jie[200005];
int devjie[200005];
int dev[200005];
int t;
int C(int n,int m)
{
	return jie[n]*devjie[m]%mod*devjie[n-m]%mod; 
}
char s[100005][4];
signed main() 
{
	jie[0]=devjie[0]=1;dev[1]=1;
	for(int i=2;i<200005;i++)
	{
		dev[i]=(mod-mod/i)*dev[mod%i]%mod; 
	}
	for(int i=1;i<200005;i++)
	{
		jie[i]=jie[i-1]*i%mod;
		devjie[i]=devjie[i-1]*dev[i]%mod;
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",s[i]);
		if(s[i][1]=='W')s[i][1]='B';
		else if(s[i][1]=='B')s[i][1]='W';
	}
	int ans=0;
	int w1=0,b1=0,w2=0,b2=0;
	for(int i=0;i<n;i++)
	{
		if(s[i][0]=='W')w1++;
		else if(s[i][0]=='B')b1++;
		if(s[i][1]=='W')w2++;
		else if(s[i][1]=='B')b2++;
	}
	for(int i=0;i<=n-w1-b1;i++)
	{
		int ww=w1+i;
		int bb=n-ww;//cout<<ww<<"  "<<bb<<"   "<<C(n-w2-b2,w2-ww)*C(n-w1-b1,i)%mod<<endl; 
		if(ww<w2||bb<b2)continue;
		ans+=C(n-w2-b2,ww-w2)*C(n-w1-b1,i)%mod;
	}
	int ans2=1;
	for(int i=0;i<n;i++)
	{
		if(s[i][0]=='B'&&s[i][1]=='W')ans2=0;
		if(s[i][0]=='W'&&s[i][1]=='B')ans2=0;
		if(s[i][0]=='?'&&s[i][1]=='?')ans2=ans2*2%mod;
	}
	//cout<<"<<<"<<ans<<"   "<<ans2<<endl; 
	//+1 +1
	bool flag=1;
	for(int i=0;i<n;i++)
	{
		if(s[i][0]=='W'||s[i][1]=='W')flag=0;
	}
	ans+=flag;
	flag=1;
	for(int i=0;i<n;i++)
	{
		if(s[i][0]=='B'||s[i][1]=='B')flag=0;
	}
	ans+=flag;
	ans-=ans2;
	ans%=mod;
	if(ans<0)ans+=mod;
	cout<<ans<<endl;
    return 0;
}