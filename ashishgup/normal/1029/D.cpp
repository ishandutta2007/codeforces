#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, k, ans=0;
int a[N];
unordered_map<int, int> m[11];

int work(int idx)
{
	int cur=a[idx]%k;
	int len=0;
	int temp=a[idx];
	int extra=cur;
	while(temp>0)
	{
		len++;
		temp/=10;
		extra*=10;
		extra%=k;
	}
	int reqd=(k-cur)%k;
	ans+=m[len][reqd];
	if(extra==reqd)
		ans--;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=0;i<=10;i++)
	{
		m[i].reserve(1<<15);
		m[i].max_load_factor(0.25);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[0][a[i]%k]++;
		int cur=a[i]%k;
		for(int j=1;j<=10;j++)
		{
			cur*=10;
			cur%=k;
			m[j][cur]++;
		}
	}
	for(int i=1;i<=n;i++)
		work(i);
	cout<<ans;
	return 0;
}