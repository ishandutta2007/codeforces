
 #include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=505;

int x, n;
string s;
int cache[N][N], cache2[N][N];

int dp2(int l, int r)
{
	if(l>=r)
		return 0;
	if(cache2[l][r]!=-1)
		return cache2[l][r];
	int &ans=cache2[l][r];
	ans=(s[l]!=s[r]) + dp2(l+1, r-1);
	return ans;
}

int dp(int idx, int k)
{
	if(idx>=n)
		return 0;
	if(k==1)
		return dp2(idx, n-1);
	int &ans=cache[idx][k];
	if(ans!=-1)
		return ans;
	ans=n-idx+1;
	for(int i=idx;i<n;i++)
		ans=min(ans, dp2(idx, i) + dp(i+1, k-1));
	return ans;
}

void path(int idx, int k)
{
	if(idx>=n)
		return;
	if(k==1)
	{
		for(int p=idx, q=n-1;p<q;p++, q--)
			if(s[p]!=s[q])
				s[q]=s[p];
		cout<<s.substr(idx);
		return;
	}
	int &ans=cache[idx][k];
	for(int i=idx;i<n;i++)
	{
		if(ans == dp2(idx, i) + dp(i+1, k-1))
		{
			for(int p=idx, q=i;p<q;p++, q--)
				if(s[p]!=s[q])
					s[q]=s[p];
			cout<<s.substr(idx, i-idx+1);
			if(i+1!=n)
				cout<<"+";
			return path(i+1, k-1);
		}
	}
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	cin>>s>>x;
	n=s.size();
	int ans=dp(0, x);
	cout<<ans<<endl;
	path(0, x);
	return 0;
}