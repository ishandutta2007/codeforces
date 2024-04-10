#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;
const int MOD=998244353;

string s, l, r;
int n, p, q;
int cache[N];
int inc[N], decr[N];
vector<int> zl, zr;

vector<int> z_function(string &s)
{
	int n=s.size();
	vector<int> z(n);
	for(int i=1,l=0,r=0;i<n;i++)
	{
		if(i<=r)
			z[i]=min(r-i+1, z[i-l]);
		while(i+z[i]<n && s[z[i]]==s[i+z[i]])
			z[i]++;
		if(i+z[i]-1>r)
			l=i, r=i+z[i]-1;
	}
	return z;
}

int dp(int idx)
{	
	if(idx>n)
		return 0;
	if(idx==n)
		return 1;
	int &ans=cache[idx];
	if(ans!=-1)
		return ans;
	ans=0;
	if(s[idx]=='0')
	{
		if(l=="0")
			return ans=(2*dp(idx+1) - dp(idx+2) + MOD)%MOD;
		return ans=dp(idx+1);
	}
	int lidx=idx+p+inc[idx];
	int ridx=min(n, idx+q-decr[idx]);
	if(lidx<=n)
		ans+=dp(lidx) - dp(ridx+1);
	ans+=MOD;
	ans%=MOD;
	ans+=dp(idx+1);
	ans%=MOD;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>s>>l>>r;
	n=s.size();
	p=l.size();
	q=r.size();
	string temp=l + "#" + s;
	zl=z_function(temp);
	for(int i=0;i<n;i++)
	{
		int idx=zl[i+p+1];
		if(idx<p && i+idx<n && s[i+idx]<l[idx])
			inc[i]=1;
	}
	temp=r + "#" + s;
	zr=z_function(temp);
	for(int i=0;i<n;i++)
	{
		int idx=zr[i+q+1];
		if(idx<q && i+idx<n && s[i+idx]>r[idx])
			decr[i]=1;
	}
	int ans=dp(0)-dp(1);
	ans+=MOD;
	ans%=MOD;
	cout<<ans;
	return 0;
}