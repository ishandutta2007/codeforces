#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, idx=0;
string s;
int cnt[N];

int32_t main()
{
	IOS;
	cin>>s;
	n=s.size();
	int r=(n+19)/20;
	int c=(n+r-1)/r;
	int extra=r*c - n;
	for(int i=1;i<=r;i++)
		cnt[i]=extra/r + (i<=(extra%r));
	cout<<r<<" "<<c<<endl;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=cnt[i];j++)
			cout<<"*";
		for(int j=cnt[i]+1;j<=c;j++)
			cout<<s[idx++];
		cout<<endl;
	}
	return 0;
}