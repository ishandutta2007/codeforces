#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N = 2e5 + 5;

int n, h, sum = 0, mn = 1e18, cur = 0, answer = 0;
int a[N];

int check(int k)
{
	double cur = 1.0l * h + 1.0l * k * sum + mn;
	if(cur < -1)
		return 0;
	int cur2 = h + k * sum + mn;
	return cur2 >= 1;
}

int binsearch(int lo, int hi)
{
	while(lo < hi)
	{
		int mid = (lo + hi + 1)/2;
		if(check(mid))
			lo = mid;
		else
			hi = mid - 1;
	}
	return lo;
}

void work()
{
	for(int i=1;i<=n;i++)
	{
		answer++;
		h += a[i];
		if(h <= 0)
		{
			cout<<answer;
			exit(0);
		}
	}
}

int32_t main()
{
	IOS;
	cin>>h>>n;
	cur = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum += a[i];
		cur += a[i];
		if(h + cur <= 0)
		{
			cout<<i;
			return 0;
		}
		mn = min(mn, cur);
	}
	if(sum >= 0)
	{
		cout<<"-1";
		return 0;
	}
	int take = binsearch(0, 1e12);
	answer = take * n;
	h += sum * take;
	while(true)
		work();
	return 0;
}