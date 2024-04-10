#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=150;

int n, x, y;
int a[N];
map<int, int> m;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
	}
	sort(a+1, a+n+1);
	x=a[n];
	for(int i=1;i*i<=x;i++)
	{
		if(x%i==0)
		{
			m[i]--;
			if(m[i]==0)
				m.erase(i);
			if(i==x/i)
				continue;
			m[x/i]--;
			if(m[x/i]==0)
				m.erase(x/i);
		}
	}
	int y=m.rbegin()->first;
	cout<<x<<" "<<y;
	return 0;
}