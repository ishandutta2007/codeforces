#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;
const int MOD=998244353;

int n, ans=1;
int a[N];
map<int, int> last;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		last[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(i>1)
		{
			ans*=2;
			ans%=MOD;
		}
		int cur=last[a[i]];
		int idx=i+1;
		while(idx<=cur)
		{
			cur=max(cur, last[a[idx]]);
			idx++;
		}
		i=cur;
	}
	cout<<ans;
	return 0;
}