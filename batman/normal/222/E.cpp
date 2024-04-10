#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll N=301*1000;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)1e9);



struct Mat{
	ll n,m,a[70][70];
	Mat(ll x,ll y,ll num=0){
		n=x;m=y;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				a[i][j]=num;
	}
	Print(){
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cout<<a[i][j]<<" ";
			cout<<"\n";
		}
	}
};

Mat operator *(const Mat &a,const Mat &b)
{
	Mat ans(a.n,b.m);
	for(int i=0;i<a.n;i++)
		for(int j=0;j<b.m;j++)
			for(int k=0;k<a.m;k++)
				ans.a[i][j]+=a.a[i][k]*b.a[k][j],ans.a[i][j]%=MOD,ans.a[i][j]+=MOD,ans.a[i][j]%=MOD;
	return ans;
}

Mat power(Mat p,ll k)
{
	Mat ans(p.n,p.n);
	for(int i=0;i<ans.n;i++)ans.a[i][i]=1;
	while(k)
	{
		if(k%2)ans=ans*p;
		k/=2;
		p=p*p;
	}
	return ans;
}

ll n,m,k;

main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	Mat p(m,m,1);
	for(ll i=0;i<k;i++)
	{
		ll ex[2];
		string s;
		cin>>s;
		if(s[0]>='A' && s[0]<='Z')ex[0]=(s[0]-'A')+26;
		else ex[0]=s[0]-'a';
		if(s[1]>='A' && s[1]<='Z')ex[1]=(s[1]-'A')+26;
		else ex[1]=s[1]-'a';
		//cout<<ex[1]<<" "<<ex[0]<<"\n";
		p.a[ex[0]][ex[1]]=0;
	}
	//cout<<"hir";
	p=power(p,n-1);
	ll ans=0;
	for(int i=0;i<m;i++)for(int j=0;j<m;j++)ans+=p.a[i][j],ans%=MOD;
	cout<<ans;
	return 0;
}