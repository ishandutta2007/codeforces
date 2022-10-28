#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<"-1";
		return 0;
	}
	sort(a+1, a+n+1);
	set<int> diff;
	for(int i=1;i<n;i++)
	{
		diff.insert(a[i+1]-a[i]);
	}
	if(diff.size()==1)
	{
		int d=*(diff.begin());
		if(d==0)
		{
			cout<<"1"<<endl;
			cout<<a[1];
			return 0;
		}
		if(n>2)
		{
			cout<<"2"<<endl;
			cout<<a[1]-d<<" "<<a[n]+d;
		}
		else if(n==2)
		{
			if(d%2)
			{
				cout<<"2"<<endl;
				cout<<a[1]-d<<" "<<a[n]+d;
			}
			else
			{
				cout<<"3"<<endl;
				cout<<a[1]-d<<" "<<a[1]+d/2<<" "<<a[n]+d;
			}
		}
		return 0;
	}
	if(diff.size()>=3)
	{
		cout<<"0";
		return 0;
	}
	int left=*(diff.begin());
	int right=*(++diff.begin());
	if(right!=2*left)
	{
		cout<<"0";
	}
	else
	{
		int ct=0;
		int ind;
		for(int i=2;i<=n;i++)
		{
			if(a[i]-a[i-1]==right)
			{
				ind=i-1;
				ct++;
			}
		}
		if(ct>1)
		{
			cout<<"0";
		}
		else
		{
			cout<<"1"<<endl;
			cout<<a[ind]+right/2;
		}
	}
}