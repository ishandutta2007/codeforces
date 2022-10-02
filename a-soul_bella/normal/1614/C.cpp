#include <bits/stdc++.h>
#define mod 1000000007
#define int long long
using namespace std;
inline int ksm(int x,int y)
{
	int rtn=1;
	while(y)
	{
		if(y&1) rtn=rtn*x%mod;
		x=x*x%mod,y>>=1;
	}
	return rtn;
}
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int Or=0;
		int n,m;
		cin >> n >> m;
		while(m--)
		{
			int x,y,z;
			cin >> x >> y >> z;
			Or|=z;
		}
		cout << ksm(2,n-1)*Or%mod << "\n"; 
	}
	return 0;
}