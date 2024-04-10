#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 2e4 + 5;

vector<int> divisors[N];

void precompute()
{
	for(int i = 1; i < N; i++)
	{
		for(int j = 1; i * j < N; j++)
			divisors[i * j].push_back(i);
	}
}

int32_t main()
{
	IOS;
	precompute();
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 2e9;
		int ansA, ansB, ansC;
		for(int i = 1; i <= 2e4; i++)
		{
			int sz = divisors[i].size();
			for(int j = 0; j < sz; j++)
			{
				for(int k = 0; k <= j; k++)
				{
					if(divisors[i][j] % divisors[i][k] == 0)
					{
						int reqd = abs(c - i) + abs(b - divisors[i][j]) + abs(a - divisors[i][k]);
						if(reqd < ans)
						{
							ans = reqd;
							ansA = divisors[i][k], ansB = divisors[i][j], ansC = i;
						}
					}
				}
			}
		}
		cout << ans << endl;
		cout << ansA << " " << ansB << " " << ansC << endl; 
	}
	return 0;
}