#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 3e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	vector<int> xorVal(N, 0);
	for(int i = 1; i < N; i++)
		xorVal[i] = xorVal[i - 1] ^ i;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		int mnLen = a;
		int val = xorVal[a - 1];
		if(val != b)
		{
			int req = val ^ b;
			if(req == a)
				cout << mnLen + 2 << endl;
			else
				cout << mnLen + 1 << endl;
		}
		else
			cout << mnLen << endl;
	}
	return 0;
}