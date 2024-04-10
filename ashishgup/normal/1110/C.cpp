#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = (1LL << 25);

int n;
int spf[N];

void precompute()
{
	for(int i = 2; i < N; i++)
	{
		if(!spf[i])
		{
			spf[i] = i;
			for(int j = 1; i * j < N; j++)
				if(!spf[i * j])
					spf[i * j] = i;
		}
	}
}

bool checkPow2(int x)
{
	return ((x & (x - 1)) == 0);
}

int32_t main()
{
	IOS;
	precompute();
	int t;
	cin >> t;
	while(t--)
	{
		int x;
		cin >> x;
		if(checkPow2(x + 1))
			cout << x / spf[x] << endl;
		else
		{
			int flag = 0;
			for(int b = 25; b >= 0; b--)
			{
				if(x >> b & 1)
					flag = 1;
				else if(flag)
					x |= (1 << b);
			}
			cout << x << endl;
		}
	}
	return 0;
}