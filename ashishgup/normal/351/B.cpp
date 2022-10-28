#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3005;

int n;
int a[N], bit[N];

void update(int i, int k)
{
	while(i<=n)
	{
		bit[i]+=k;
		i+=(i&(-i));
	}
}

int pref(int i)
{
	int ans=0;
	while(i>0)
	{
		ans+=bit[i];
		i-=(i&(-i));
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	reverse(a+1, a+n+1);
	int inv=0;
	for(int i=1;i<=n;i++)
	{
		inv+=pref(a[i]);
		update(a[i], 1);
	}
	int ans=inv%2 + (inv-inv%2)*2;
	cout<<fixed<<setprecision(12)<<(double)ans;
	return 0;
}