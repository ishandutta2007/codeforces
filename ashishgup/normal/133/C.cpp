#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
string s;
int previous=0;

int rev(int x)
{
	int ans=0;
	for(int i=0;i<8;i++)
	{
		if(x>>i & 1)
			ans+=(1LL<<(7-i));
	}
	return ans;
}

int32_t main()
{
	IOS;
	getline(cin, s);
	n=s.size();
	for(int i=0;i<n;i++)
	{
		int val=rev(previous);
		int cur=rev(s[i]);
		val=(val-cur+256)%256;
		previous=s[i];
		cout<<val<<endl;
	}	
	return 0;
}