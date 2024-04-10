#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	string a, b;
	cin>>a>>b;
	int l=0, r=b.size()-1, idx=0;
	while(l<b.size())
	{
		if(a[idx]==b[l])
			idx++;
		if(idx==a.size())
			break;
		l++;
	}
	idx=a.size()-1;
	while(r>=0)
	{
		if(a[idx]==b[r])
			idx--;
		if(idx<0)
			break;
		r--;
	}
	int ans=max(0LL, r-l);
	cout<<ans;
	return 0;
}