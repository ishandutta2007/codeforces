#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		sort(a+1,a+n+1);
		for(int i=2;i<=2+(n/2)-1;i++)
		{
			cout << a[i] << " " << a[1] << "\n"; 
		}
	}
	return 0;
}