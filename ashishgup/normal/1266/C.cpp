#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 505;

int r, c;
int a[N][N];

bool check()
{
	set<int> s;
	for(int i = 1; i <= r; i++)
	{
		int g = 0;
		for(int j = 1; j <= c; j++)
			g = __gcd(g, a[i][j]);
		s.insert(g);
	}
	for(int i = 1; i <= c; i++)
	{
		int g = 0;
		for(int j = 1; j <= r; j++)
			g = __gcd(g, a[j][i]);
		s.insert(g);
	}
	if(s.size() == r + c)
		return 1;
	return 0;
}

void print()
{
	for(int i = 1; i <= r; i++)
	{
		for(int j = 1; j <= c; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

int32_t main()
{
	IOS;
	cin >> r >> c;
	if(r == 1 && c == 1)
	{
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= c; j++)
			a[i][j] = i * (j + i);
	if(check())
		print();
	else
	{
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= c; j++)
				a[i][j] = (i + c) * (j);
		if(check())
			print();
		else
			cout << 0;
	}
	return 0;
}