#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, c;
int invalid[N];
vector<int> v[N];

void work(int i)
{
	for(int j=1;j<=min(v[i][0], v[i+1][0]);j++)
	{
		if(v[i][j]<v[i+1][j])
		{
			int curl=0, curr=(c-v[i+1][j]);
			int nextl=(c-v[i][j]+1);
			invalid[curr+1]+=1;
			invalid[nextl]-=1;
			return;
		}
		else if(v[i][j]>v[i+1][j])
		{
			int curl=(c-v[i][j]+1), curr=(c-v[i+1][j]);
			invalid[0]+=1;
			invalid[curl]-=1;
			invalid[curr+1]+=1;
			invalid[c]-=1;
			return;
		}
	}
	if(v[i][0]>v[i+1][0])
	{
		cout<<"-1";
		exit(0);
	}
}

int32_t main()
{
	IOS;
	cin>>n>>c;
	for(int i=1;i<=n;i++)
	{
		int l;
		cin>>l;
		v[i].push_back(l);
		for(int j=1;j<=l;j++)
		{
			int val;
			cin>>val;
			v[i].push_back(val);
		}
	}
	for(int i=1;i<=n-1;i++)
		work(i);
	for(int i=0;i<c;i++)
	{
		if(invalid[i]==0)
		{
			cout<<i;
			return 0;
		}
		invalid[i+1]+=invalid[i];
	}
	cout<<"-1";
	return 0;   
}