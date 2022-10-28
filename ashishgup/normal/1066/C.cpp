#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int store[N];

int32_t main()
{
	IOS;
	int q, l=0, r=0;
	cin>>q;
	while(q--)
	{
		char ch;
		cin>>ch;
		int id;
		cin>>id;
		if(ch=='L')
		{
			store[id]=l--;
			if(r==0)
				r++;	
		}
		else if(ch=='R')
		{
			store[id]=r++;
			if(l==0)
				l--;
		}
		else
		{
			int idx=store[id];
			int ans=min(idx-l, r-idx);
			ans--;
			cout<<ans<<endl;
		}
	}
	return 0;
}