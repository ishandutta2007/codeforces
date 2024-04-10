#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int a[N];

pair<int, int> get(int s, int x)
{
	int A = (s - x) / 2;
	int a = 0, b = 0;
	for(int i = 0; i < 60; i++)
	{
		int Xi = (x >> i & 1);
		int Ai = (A >> i & 1);	
		if(Xi == 0 && Ai > 0)
		{
			a |= 1LL << i;
			b |= 1LL << i;
		}
		else if(Xi > 0 && Ai == 0)
		{
			a |= 1LL << i;
		}
		else if(Xi == 1 && Ai == 1)
			return {-1, -1};
	}
	return {a, b};

}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int sum = 0, xorS = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			sum += a[i];
			xorS ^= a[i];
		}
		vector<int> v;
		sum += xorS;
		v.push_back(xorS);
		for(int i = 5; i < 60; i++)
		{
			int final = (1LL << i);
			int add = (final - sum);
			if(add > 0 && get(add, final / 2).first != -1)
			{
				pair<int, int> p = get(add, final / 2);
				v.push_back(p.first);
				v.push_back(p.second);
				cout << v.size() << endl;
				for(auto &it:v)
					cout << it << " ";
				cout << endl;
				break;
			}
		}
	}
	return 0;
}