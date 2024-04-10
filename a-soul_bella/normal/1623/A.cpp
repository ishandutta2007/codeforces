#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,m,a,b,c,d;
		cin >> n >> m >> a >> b >> c >> d;
		int d1=0,d2=0;
		if(a<=c) d1=c-a;
		else d1=n+n-a-c;
		if(b<=d) d2=d-b;
		else d2=m+m-d-b;
		cout << min(d1,d2) << "\n"; 
	}
	return 0;
}