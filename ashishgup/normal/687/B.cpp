#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, k;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>k;
	set<int> s;
	int storek=k;
	for(int i=2;i<=k;i++)
	{
		while(k%i==0)
		{
			k/=i;
			s.insert(i);
		}
	}
	map<int, int> m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(auto it:s)
		{
			int cntr=0;
			while(a[i]%it==0)
			{
				cntr++;
				a[i]/=it;
			}
			m[it]=max(m[it], cntr);
		}
	}
	for(auto &it:m)
	{
		while(storek%it.first==0 && it.second>0)
		{
			storek/=it.first;
			it.second--;
		}
	}
	if(storek==1)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}