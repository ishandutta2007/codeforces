#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a,b,c,cnt[100005];
inline int solve(string s)
{
	n=s.size();
	int X=0,Y=0;
	for(int i=0;i<=n;i++) cnt[i]=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0') ++X;
		else break;
	}
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]=='0') ++Y;
		else break;
	}
	int now=0,mx1=-1;
	for(auto t:s) if(t=='1') ++mx1;
	for(auto t:s)
	{
		if(t=='0') ++now;
		else ++cnt[now],now=0;
	}
	if(now) ++cnt[now];
	--cnt[X],--cnt[Y];
	int one=0;
	for(int i=1;i<n;i++)
		if(s[i]==s[i-1]&&s[i]=='1') ++one;
	int rtn=0,mn=1;
	for(int i=2;i<=n;i++)
	{
		if(cnt[i])
		{
			mn=i;
			break;
		}
	}
	while((mn>1||X>1||Y>1)&&one)
	{
		if(mn>1)
		{
			--cnt[mn],++cnt[mn-1];
			if(--mn==1)
			{
				for(int i=2;i<=n;i++)
				{
					if(cnt[i])
					{
						mn=i;
						break;
					}
				}
			}
		}
		else if(X>1) --X;
		else if(Y>1) --Y;
		--one,rtn+=a+b,--mx1;
	}
	now=rtn;
	if(mn>1||X>1||Y>1) rtn=max(rtn,now+a);
	while(cnt[1]&&mx1>0)
	{
		--mx1;
		--cnt[1],now-=c,now+=b;
		rtn=max(rtn,now);
	}
	if(one>0&&X>=1)
	{
		--one,X=0;
		now-=c,now+=b;
		rtn=max(rtn,now);
	}
	if(one>0&&Y>=1)
	{
		--one,Y=0;
		now-=c,now+=b;
		rtn=max(rtn,now);
	}
	if(mn>1||X>1||Y>1) rtn=max(rtn,now+a);
	return rtn;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> a >> b >> c;
		string s;
		cin >> s;
		int ans=solve(s);
		for(int i=1;i<s.size();i++)
		{
			if(s[i]=='1'&&s[i-1]=='1')
			{
				string S;
				for(int j=0;j<i;j++) S+=s[j];
				for(int j=i+1;j<s.size();j++) S+=s[j];
				ans=max(ans,solve(S)+b);
				break; 
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
1
9 9 8 2
010000101
*/