#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int MOD=1e9+7;

vector<int> v;

void factorise(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		int cnt=0;
		while(x%i == 0)
		{
			cnt++;
			x/=i;
		}
		if(cnt)
			v.push_back(i);
	}
	if(x>1)
		v.push_back(x);
}

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int n, x, y, ans=0;

int32_t main()
{
	IOS;
	cin>>x>>y;
	if(y%x!=0)
	{
		cout<<"0";
		return 0;
	}
	y/=x;
	factorise(y);
	n=v.size();
	for(int i=0;i<(1<<n);i++)
	{
		int cnt=0, cur=1;
		for(int j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				cnt++;
				cur*=v[j];
			}
		}
		int curgcd=y/cur;
		int contrib=pow(2LL, curgcd-1, MOD);
		if(cnt&1)
			ans-=contrib;
		else
			ans+=contrib;
		ans+=MOD;
		ans%=MOD;
	}
	cout<<ans;
	return 0;
}