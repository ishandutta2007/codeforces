#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], freq[N], cache[N];

int dp(int i)
{
	if(i>1e5)
		return 0;
	int &ans=cache[i];
	if(ans!=-1)
		return ans;
	if(!freq[i])
		ans=dp(i+1);
	else
		ans=max(freq[i]*i + dp(i+2), freq[i+1]*(i+1) + dp(i+3));
	return ans;

}
int32_t main()
{
	memset(cache, -1, sizeof(cache));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		freq[a[i]]++;
	}
	int ans=dp(1);
	cout<<ans;
	return 0;
}