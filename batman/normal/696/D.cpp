#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)202)
#define K ((ll)26)
#define INF ((ll)2e18)

struct Mat
{
	ll a[N][N],n,m;
	Mat(){for(int i=0;i<N;i++)for(int j=0;j<N;j++)a[i][j]=-INF;}
	Mat operator *(Mat x)
	{
		Mat ex;ex.n=n;ex.m=x.m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				for(int k=0;k<x.n;k++)
					ex.a[i][j]=max(ex.a[i][j],a[i][k]+x.a[k][j]);
		return ex;
	}
	Mat operator ^(ll num)
	{
		Mat ex,now=*this;ex.n=ex.m=n;
		for(int i=0;i<n;i++)ex.a[i][i]=0;
		while(num)
		{
			if(num%2)ex=ex*now;
			now=now*now;
			num/=2;
		}
		return ex;
	}
};

ll n,l,a[N],cnt[N];
string s[N];
vector <string> v;
Mat res;

int main()
{
	cin>>n>>l;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		string t="";
		for(int j=0;j<s[i].size();j++)
		{
			t+=s[i][j];
			v.push_back(t);
		}
	}
	v.push_back("");
	sort(v.begin(),v.end());v.resize(unique(v.begin(),v.end())-v.begin());
	res.n=res.m=v.size();
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<n;j++)
			if(s[j].size()<=v[i].size())
			{
				bool flg=1;
				for(int p=(ll)v[i].size()-(ll)s[j].size(),q=0;p<v[i].size();p++,q++)
					if(v[i][p]!=s[j][q])
					{
						flg=0;
						break;
					}
				if(flg)cnt[i]+=a[j];
			}
	}
	for(int i=0;i<v.size();i++)
	{
		for(int t=0;t<26;t++)
			for(int j=0;j<v.size();j++)
				if(v[j].size()<=(ll)v[i].size()+1)
				{
					bool flg=1;
					for(int p=(ll)v[i].size()-(ll)v[j].size()+1,q=0;p<v[i].size();p++,q++)
						if(v[i][p]!=v[j][q])
						{
							flg=0;
							break;
						}
					if(v[j].size() && (char)(t+'a')!=v[j][(ll)v[j].size()-1])flg=0;
					if(flg)res.a[i][j]=cnt[j];
				}
	}
	res=res^l;
	ll ans=0;
	for(int i=0;i<res.m;i++)ans=max(ans,res.a[0][i]);
	cout<<ans;
	return 0;
}