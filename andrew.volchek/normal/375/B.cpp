#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <bitset>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull long long
#define fst first
#define snd second
#define ld long double
#define y1 _y1

const int maxn = 5005;
char a[maxn][maxn];

int main()
{
	//freopen("a.in", "r", stdin);
	
	int n, m;
	scanf("%d %d\n", &n, &m);
	
	for (int i = 0; i < n; i++)
		gets(a[i]);
		
	int ans = 0;
	
	vector < pair < int, int > > v;
	
	for (int i = 0; i < n; i++)
		v.pb(mp(i, 0));
		
	for (int i = m-1; i >= 0; i--)
	{
		vector < pair < int, int > > ones, zeros;
		
		for (int j = 0; j < n; j++)
		{
			if (a[v[j].fst][i] == '1')
			{
				ones.pb(mp(v[j].fst, v[j].snd + 1));
			}
			else
			{
				zeros.pb(mp(v[j].fst, 0));
			}
		}
		
		v.clear();
		
		for (int j = 0; j < ones.size(); j++)
			v.pb(ones[j]);
			
		for (int j = 0; j < zeros.size(); j++)
			v.pb(zeros[j]);
			
		int curr = 1e9;
		
		for (int j = 0; j < n; j++)
		{
			curr = min(curr, v[j].snd);
			ans = max(ans, curr * (j + 1));
		}
	}
	
	cout << ans;
	
		
	return 0;
}