//By Don4ick 
//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qewr1234

const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};

const int N = (int)1e6 + 228;

using namespace std;

int x;
bool prime[N];

bool check(int pos)
{
	int npos = pos;
	for (int i = 2; i < pos; i++)
	{
		if (!prime[i]  && (pos + i - 1) / i * i <= x)
		{
			npos = max((pos + i - 1) / i * i, npos);		
		}
	}
	pos = npos;
	for (int i = 2; i < pos; i++)
	{
		if (!prime[i] && (pos + i - 1) / i * i == x)
			return true;
	}
	return false;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie();
	//cout.tie();		

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	//~precalc prime
	for (int i = 2; i < N; i++)
	{
		if (!prime[i])
		{
			for (int j = i + i; j < N; j += i)
				prime[j] = true;
		}
	}
	//~read
	cin >> x;
	int l = 2, r = x; 
	while(l < r - 1)	
	{
		int mid = (l + r) >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid;	
	}
	cout << r << endl;
	return 0;
}