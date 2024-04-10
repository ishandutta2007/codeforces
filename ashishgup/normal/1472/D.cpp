//Trying to screencast

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		int diff = 0, turn = 0;
		for(int i = n; i >= 1; i--)
		{
			if(turn == (a[i] & 1))
			{
				if(!turn)
					diff += a[i];
				else
					diff -= a[i];
			}
			turn ^= 1;
		}
		if(diff > 0)
			cout << "Alice" << endl;
		else if(diff < 0)
			cout << "Bob" << endl;
		else
			cout << "Tie" << endl;
	}
	return 0;
}