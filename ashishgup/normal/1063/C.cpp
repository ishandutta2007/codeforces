#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long

int n, orig=0;
map<pair<int, int>, int> m;

int check(int x, int y)
{
	if(m.find({x, y})!=m.end())
		return m[{x, y}];
	cout<<x<<" "<<y<<endl;
	string s;
	cin>>s;
	if(s=="white")
		return m[{x, y}]=1;
	else
		return m[{x, y}]=0;
}

void print(int x1, int y1, int x2, int y2)
{
	cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	exit(0);
}

void binsearch(int lo, int hi)
{
	int x=0;
	while(lo<hi && n>0)
	{
		n--;
		int mid=(lo+hi+1)/2;
		x=mid;
		if(check(mid, 1)==check(0, 1))
			lo=mid;
		else
			hi=mid-1;
	}
	print(lo, 0, lo+1, 2);
}

int32_t main()
{
	IOS;
	cin>>n;
	n--;
	orig=check(0, 1);
	binsearch(0, 1e9);
	return 0;
}