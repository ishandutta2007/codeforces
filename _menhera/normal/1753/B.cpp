#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, X; cin >> N >> X;
	vector<int> V(X+1);
	for(int i=0; i<N; i++)
	{
		int t; cin >> t;
		V[t]++;
	}
	long long XPi = X;
	long long rem = 0;
	for(int i=X-1; i>=1; --i)
	{
		while(V[i]--)
		{
			if(rem > 0) --rem;
			else
			{
				if(XPi > N)
				{
					cout << "No\n";
					return 0;
				}
				rem = XPi-1;
			}
		}
		if(i) rem *= i;
		if(rem > N)
		{
			cout << "No\n";
			return 0;
		}
		XPi *= i;
		if(XPi > N) XPi = N+1;
	}
	if(rem) cout << "No\n";
	else cout << "Yes\n";
}