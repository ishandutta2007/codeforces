#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		if(k % 2 == 0)
		{
			if(t == 2)
				ans ^= 2;
			else if(t == 1)
				ans ^= 1;
			else
				ans ^= t % 2 == 0;
		}
		else
		{
			if(t == 1)
				 ans ^= 1;
			else if(t == 2)
				ans ^= 0;
			else if(t == 3)
				ans ^= 1;
			else if(t == 4)
				ans ^= 2;
			else if(t % 2 == 1)
				ans ^= 0;
			else
			{
				int g = 1;
				int tr = 0;
				int tt = t;
				while(t % 2 == 0)
					t /= 2, tr++;
				if(t == 3 && tr % 2 == 1)
					g++;
				if(t != 3 && tr % 2 == 0)
					g++;
				ans ^= g;
			}
		}
	}
	cout << (ans ? "Kevin": "Nicky") << "\n";
	/*
	int t = 100;
	int g[t];
	g[0] = 0;
	for(int i = 1; i < t; i++)
	{
		vector<int> lol;
		lol.push_back(g[i - 1]);
		if(i % 2 == 0)
			if(k % 2 == 1)
				lol.push_back(g[i / 2]);
			else
				lol.push_back(0);
		sort(lol.begin(), lol.end());
		if(find(lol.begin(), lol.end(), 0) == lol.end())
			g[i] = 0;
		else if(find(lol.begin(), lol.end(), 1) == lol.end())
			g[i] = 1;
		else
			g[i] = 2;
		cout << i << ": " << g[i] << ' ';
		int t = i;
				int G = 1;
				int tr = 0;
				int tt = t;
				while(t % 2 == 0)
					t /= 2, tr++;
				if(t == 3 && tr % 2 == 1)
					G++;
				if(t != 3 && tr % 2 == 0)
					G++;
		cout << G << endl;
	}*/
    return 0;
}