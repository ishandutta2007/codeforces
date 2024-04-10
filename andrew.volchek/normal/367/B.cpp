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

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 200005;
int a[maxn], b[maxn];
vector < int > c[maxn];

int main()
{
	//freopen("a.in", "r", stdin);
	
	int n, m, p;
	scanf("%d %d %d", &n, &m, &p);
	
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
		
	for (int i = 0; i < m; i++)
		scanf("%d", b + i);
		
	map < int, int > mm;
	for (int i = 0; i < m; i++)
		mm[b[i]]++;
		
	
	for (int i = 0; i < min(n, p); i++)
	{
		for (int j = i; j < n; j += p)
			c[i].pb(a[j]);
	}
	
	int zeroCnt = 0;
	vector < int > ans;
	
	for (int i = 0; i < p; i++)
	{
		int currCnt = 0;
		zeroCnt = 0;
		for (int j = 0; j < c[i].size(); j++)
		{
			currCnt++;
			if (mm.find(c[i][j]) != mm.end())
			{
				if (mm[c[i][j]] == 1)
					zeroCnt++;
				if (mm[c[i][j]] == 0)
					zeroCnt--;
				mm[c[i][j]]--;
			}
			if (currCnt > m)
			{
				currCnt--;
				if (mm.find(c[i][j-m]) != mm.end())
				{
					if (mm[c[i][j-m]] == -1)
						zeroCnt++;
					if (mm[c[i][j-m]] == 0)
						zeroCnt--;
					mm[c[i][j-m]]++;
				}
			}
			
			if (zeroCnt == mm.size())
			{
				ans.pb(i + (ll)(j-m+1) * p);
			}
		}
		
		for (int j = (int)c[i].size() - currCnt; j < c[i].size(); j++)
		{
			if (mm.find(c[i][j]) != mm.end())
			{
				mm[c[i][j]]++;
			}
		}
	}
		
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		if (i)
			printf(" ");
		printf("%d", ans[i] + 1);
	}
	
	
	return 0;
}