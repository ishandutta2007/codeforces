#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int n, l=1e3, r=0;
vector<int> a, b, c;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}	
	b=a;
	sort(b.begin(), b.end());
	if(a==b)
	{
		cout<<"0 0";
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
			l=min(l, i), r=max(r, i);
	}
	reverse(a.begin()+l, a.begin()+r+1);
	if(a==b)
		cout<<l+1<<" "<<r+1;
	else
		cout<<0<<" "<<0;
	return 0;
}