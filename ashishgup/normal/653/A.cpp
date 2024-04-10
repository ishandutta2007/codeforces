#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e5+5;

int n;
int a[N];

bool check(int i, int j, int k)
{
	set<int> s;
	s.insert(a[i]);
	s.insert(a[j]);
	s.insert(a[k]);
	if(s.size()!=3 || (*(--s.end())-*(s.begin())>2))
		return 0;
	return 1;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(check(i, j, k))
				{
					cout<<"YES";
					return 0;
				}
			}
		}
	}
	cout<<"NO";
    return 0;
}