#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n;
int a[N], b[N];

void check(int k)
{
	for(int i=2;i<=n;i++)
	{
		if(a[i]%k==0 || b[i]%k==0)
			continue;
		return;
	}
	cout<<k;
	exit(0);
}

void factorise(int k)
{
	vector<int> v;
	for(int i=2;i*i<=k;i++)
	{
		int ct=0;
		while(k%i==0)
		{
			k/=i;
			ct++;
		}
		if(ct>0)
			v.push_back(i);
	}
	if(k>1)
		v.push_back(k);
	for(auto &it:v)
		check(it);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	factorise(a[1]);
	factorise(b[1]);
	cout<<"-1";
	return 0;
}