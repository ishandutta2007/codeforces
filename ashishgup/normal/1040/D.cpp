#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long

int n, k;
int printed=0;
random_device rd;
mt19937 rng(rd()); 

int getRand(int l, int r)
{
	uniform_int_distribution<int> uid(l, r);
	return uid(rng); 
}

int print(int l, int r)
{
	printed++;
	if(printed==4501)
	{
		assert(false);
	}
	cout<<l<<" "<<r<<endl;
	string s;
	cin>>s;
	if(s=="Yes")
	{
		if(l==r)
			exit(0);
		return 1;
	}
	else
		return 0;
}

void binsearch(int lo, int hi)
{
	while(hi-lo>6*k)
	{
		int mid=(lo+hi)/2;
		if(print(lo, mid))
		{
			lo=max(1LL, lo-k);
			hi=min(hi, mid+k);
		}
		else
		{
			lo=max(1LL, mid-k+1);
			hi=min(n, hi+k);
		}
	}
	int cur=getRand(lo, hi);
	print(cur, cur);
	binsearch(max(1LL, lo-k), min(hi+k, n));
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	binsearch(1, n);
	return 0;
}