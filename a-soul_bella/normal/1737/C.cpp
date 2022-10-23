#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int a,b,c,d,e,f,n;
		cin >> n;
		cin >> a >> b >> c >> d >> e >> f;
		int X,Y;
		if(a==c||a==e) X=a;
		else X=c;
		if(b==d||b==f) Y=b;
		else Y=d;
		int x,y;
		cin >> x >> y;
		if(X==1&&Y==1)
		{
			if(x==1||y==1) cout << "YES\n";
			else cout << "NO\n";
			continue;
		}
		if(X==n&&Y==n)
		{
			if(x==n||y==n) cout << "YES\n";
			else cout << "NO\n";
			continue;
		}
		if(X==1&&Y==n)
		{
			if(x==1||y==n) cout << "YES\n";
			else cout << "NO\n";
			continue;
		}
		if(X==n&&Y==1)
		{
			if(x==n||y==1) cout << "YES\n";
			else cout << "NO\n";
			continue;
		}
		x%=2,y%=2;
		X%=2,Y%=2;
		if(x!=X&&y!=Y) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}