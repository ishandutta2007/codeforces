#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, p, q; string ss; cin >> n >> p >> q >> ss;
	for(int i=0; i<=n; ++i) for(int j=0; j<=n; ++j)
	{
		if(p*i+q*j == n)
		{
			int it = 0;
			cout << i + j << endl;
			for(int k=0; k<i; ++k)
			{
				for(int s=0; s<p; ++s) cout << ss[it++];
				cout << endl;
			}
			for(int k=0; k<j; ++k)
			{
				for(int s=0; s<q; ++s) cout << ss[it++];
				cout << endl;
			}
			return 0;
		}
	}
	cout << -1 << endl;
}