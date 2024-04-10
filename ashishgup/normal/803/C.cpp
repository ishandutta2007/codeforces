#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int a[N], b[N];
int n, k, rem;

bool check(int g)
{
	int total=g*(k*(k+1))/2;
	if(total>n)
		return 0;
	total=n-total;
	if(total%g==0)
		return 1;
	return 0;
}

int work()
{
	priority_queue<int, vector<int> > fact;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			fact.push(i);
			fact.push(n/i);
		}
	}
	while(!check(fact.top()))
		fact.pop();
	return fact.top();
}

int construct(int g)
{
	int sum=0;
	for(int i=1;i<=k;i++)
	{
		b[i]=a[i]*g;
		sum+=b[i];
	}
	int cur_rem=n-sum;
	b[k]+=cur_rem;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	int minn=(k*(k+1))/2;
	if(k>=1e6)
	{
		cout<<"-1";
		return 0;
	}
	if(n<minn)
	{
		cout<<"-1";
		return 0;
	}
	for(int i=1;i<=k;i++)
		a[i]=i;
	int ans=work();
	construct(ans);
	for(int i=1;i<=k;i++)
		cout<<b[i]<<" ";
	return 0;
}