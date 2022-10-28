#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define x first
#define y second

const int N=1e5+5;

int n, m, k;

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	int num=n*m;
	int den=k;
	int store=__gcd(num, den);
	num/=store;
	den/=store;
	if(den>2)
	{
		cout<<"NO";
		return 0;
	}	
	int x=n, y=m;
	int cur=store;
	int temp=__gcd(cur, x);
	x/=temp;
	cur/=temp;
	y/=cur;
	if(den==1)
	{
		if(2*x<=n)
			x*=2;
		else if(2*y<=m)
			y*=2;
		else
		{
			cout<<"NO";
			return 0;
		}
	}
	pair<int, int> p1={0, 0};
	pair<int, int> p2={x, 0};
	pair<int, int> p3={0, y};
	cout<<"YES"<<endl;
	cout<<p1.x<<" "<<p1.y<<endl;
	cout<<p2.x<<" "<<p2.y<<endl;
	cout<<p3.x<<" "<<p3.y<<endl;
	return 0;
}