#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1005];
double b[1005];
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
		if(n==1)
		{
			cout << "0\n";
			continue;
		}
		int mx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				double d=(a[j]-a[i])/(double)(j-i);
				b[i]=a[i];
				for(int k=i-1;k>=1;k--) b[k]=b[k+1]-d;
				for(int k=i+1;k<=n;k++) b[k]=b[k-1]+d;
				int qwq=0;
				for(int k=1;k<=n;k++)
					qwq+=fabs(b[k]-a[k])<=1e-9;
				mx=max(mx,qwq);
			}
		}
		cout << n-mx << "\n";
	}
	return 0;
}