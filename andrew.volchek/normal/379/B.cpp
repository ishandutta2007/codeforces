#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cctype>
#include <cstring>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define y0 _y0
#define y1 _y1

int a[305];

int main()
{
	//freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector < char > ans;
	
	int pos = 0;
	
	while (pos < n)
	{
		if (pos != n-1)
		{
			for (int i = 0; i < a[pos]; i++)
			{
				ans.pb('P');
				ans.pb('R');
				ans.pb('L');
			}
			ans.pb('R');
		}
		else
		{
			for (int i = 0; i < a[pos]; i++)
			{
				ans.pb('P');
				ans.pb('L');
				ans.pb('R');
			}
		}
		
		pos++;
	}
	
	
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%c", ans[i]);
	}
	
	return 0;
}