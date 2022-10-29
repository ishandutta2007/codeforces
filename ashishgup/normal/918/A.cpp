#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
int f[N];
set<int> s;

int32_t main()
{
	IOS;
	cin>>n;
	f[0]=1;
	f[1]=1;
	s.insert(1);
	for(int i=2;;i++)
	{
		f[i]=f[i-1]+f[i-2];
		if(f[i]>n)
			break;
		s.insert(f[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(s.find(i)!=s.end())
			cout<<"O";
		else
			cout<<"o";
	}
	return 0;
}