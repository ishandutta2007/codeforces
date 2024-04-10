#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

const int N=1e5+5;

int m, n;
bool lie[N];

bool check(int cur, int idx)
{
	cout<<cur<<endl;
	int inp;
	cin>>inp;
	if(inp==0)
		exit(0);
	if(lie[idx])
		inp*=-1;
	if(inp==1)
		return 1;
	return 0;
}

int binsearch1(int lo, int hi)
{
	int idx=0;
	while(true)
	{
		int mid=(lo+hi)/2;
		if(check(mid, idx))
			lo=mid+1;
		else
			hi=mid-1;
		idx++;
		idx%=n;
	}
}

void work()
{
	binsearch1(1, m);
}

int32_t main()
{
	cin>>m>>n;
	for(int i=0;i<n;i++)
	{
		cout<<m<<endl;
		int cur;
		cin>>cur;
		if(cur==0)
			exit(0);
		if(cur==1)
			lie[i]=1;
	}
	work();
	return 0;
}