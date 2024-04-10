#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k, s, pos=1;
int mindist, maxdist;

int32_t main()
{
	IOS;
	cin>>n>>k>>s;
	mindist=k;
	maxdist=(n-1)*k;
	if(s<mindist || s>maxdist)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	for(int i=k-1;i>=0;i--)
	{
		int minleave=i;
		int cur=min(s-minleave, n-1);
		s-=cur;
		if(pos+cur<=n)
		{
			pos+=cur;
			cout<<pos<<" ";
		}
		else
		{
			pos-=cur;
			cout<<pos<<" ";
		}
	}
	return 0;
}