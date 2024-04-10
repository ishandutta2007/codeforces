#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <cassert>
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
using namespace std;

lli gcd(lli a, lli b) { return (b == 0 ? a : gcd(b, a % b)); }

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };



const int N = 1e5;
const lli mod = 1e9 + 7;
int n;
int a[110];
map <vector <int>, int> mp;
int qn[110], qn1[110];
vector <int> sm, ss, sm1;
int main()
{
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int j = 0; j < 15; j++)
		{
			if ((1 << j) & a[i]) qn[i]++;
		}
		for (int j = 15; j < 30; j++)
		{
			if ((1 << j) & a[i]) qn1[i]++;
		}
		//cout << qn[i] << " " << qn1[i] << endl;
		sm.PB(qn[i]);
		sm1.PB(qn1[i]);
		ss.PB(i);
	}
	for (int x = 0; x < (1 << 15); x++)
	{
		for (int j = 0; j < 15; j++)
		{
			if ((1 << j) & x)
			{
				for (int i = 0; i < n; i++)
				{
					if ((1 << j) & a[i])
					{
						sm[i]--;
					}
					else
					{
						sm[i]++;
					}
				}
				
			}
		}
		for (int i = 1; i < n; i++)
		{
			ss[i] = sm[0] - sm[i];
			sm[i] = qn[i];
		}
		sm[0] = qn[0];
		if (!mp[ss]) mp[ss] = x;
	}
	for (int x = 0; x < (1 << 15); x++)
	{
		x <<= 15;
		for (int j = 15; j < 30; j++)
		{
			if ((1 << j) & x)
			{
				for (int i = 0; i < n; i++)
				{
					if ((1 << j) & a[i])
					{
						sm1[i]--;
					}
					else
					{
						sm1[i]++;
					}
				}
				
			}
		}
		for (int i = 1; i < n; i++)
		{
			ss[i] = sm1[i] - sm1[0];
			sm1[i] = qn1[i];
		}
		sm1[0] = qn1[0];
		if (mp[ss])
		{
			cout << x + mp[ss] << endl;
			return 0;
		}
		x >>= 15;
	}
	cout << -1;
	return 0;
}