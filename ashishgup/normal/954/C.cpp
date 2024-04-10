#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;
const int M=1e9;

int n, x, y;
int a[N];

int getx(int k)
{
	int row=(k-1)/y + 1;
	return row;
}

int gety(int k)
{
	int col=k%y;
	if(col==0)
		col+=y;
	return col;
}

int check(int x1, int y1, int x2, int y2)
{
	set<int> s;
	s.insert(abs(x1-x2));
	s.insert(abs(y1-y2));
	set<int> shouldbe;
	shouldbe.insert(0);
	shouldbe.insert(1);
	if(s!=shouldbe)
	{
		return 1;
	}
	return 0;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	set<int> s;
	y=1;
	for(int i=2;i<=n;i++)
	{
		if(abs(a[i]-a[i-1])>1)
		{
			s.insert(abs(a[i]-a[i-1]));
		}
		if(abs(a[i]-a[i-1])==0)
		{
			cout<<"NO";
			return 0;
		}
	}
	if(s.size()>1)
	{
		cout<<"NO";
		return 0;
	}
	if(s.size()==0)
	{
		cout<<"YES"<<endl;
		cout<<M<<" "<<M;
		return 0;
	}
	y=*(s.begin());
	x=M;
	for(int i=1;i<=n-1;i++)
	{
		int curx=getx(a[i]);
		int cury=gety(a[i]);
		int nextx=getx(a[i+1]);
		int nexty=gety(a[i+1]);
		if(check(curx, cury, nextx, nexty))
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES"<<endl;
	cout<<x<<" "<<y;
	return 0;
}