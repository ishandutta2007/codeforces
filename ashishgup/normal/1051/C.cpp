#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N];
char ans[N];
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
	int cnt1=0, others=0;
	for(auto &it:m)
	{
		cnt1+=(it.second==1);
		others+=(it.second>2);
	}
	if(cnt1%2==0)
	{
		int left=cnt1/2;
		cout<<"YES"<<endl;
		for(auto &it:m)
		{
			if(it.second==1)
			{
				if(left>0)
				{
					ans[it.first]='A';
					left--;
				}
				else
					ans[it.first]='B';
			}
			else
				ans[it.first]='A';
		}
		for(int i=1;i<=n;i++)
			cout<<ans[a[i]];
	}
	else if(others>0)
	{
		cout<<"YES"<<endl;
		bool printed=0;
		int store=0;
		int left=(cnt1)/2;
		for(auto &it:m)
		{
			if(it.second==1)
			{
				if(left>0)
				{
					ans[it.first]='A';
					left--;
				}
				else
					ans[it.first]='B';
			}
			else if(it.second==2)
				ans[it.first]='A';
			else
			{
				ans[it.first]='B';
				store=it.first;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==store)
			{
				if(printed)
					cout<<"B";
				else
				{
					cout<<"A";
					printed=1;
				}
			}
			else
				cout<<ans[a[i]];
		}
	}
	else
		cout<<"NO";
	return 0;
}