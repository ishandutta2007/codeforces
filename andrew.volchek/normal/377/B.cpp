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
#include <algorithm>

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

int n, m, s;
pair < int, int > a[100005];
pair < pair < int, int >, int > b[100005];

bool check(int k)
{
	vector < int > need;
	
	for (int i = m-1; i >= 0; i -= k)
	{
		need.pb(a[i].fst);
	}
	
	reverse(need.begin(), need.end());
	
	
	
	int p = (int)need.size() - 1;
	ll sum = 0;
	
	int v = n-1;
	multiset < int > ss;
	
	for (;v >= 0 && p >= 0; v--)
	{
		if (b[v].fst.fst < need[p])
		{
			if (ss.empty())
				return false;
				
			sum += (ll)*ss.begin();
			ss.erase(ss.begin());
			
			p--;
			v++;
			continue;
		}
		
		
		ss.insert(b[v].fst.snd);
	}
	
	
	
	while (p >= 0)
	{
		if (ss.empty())
			return false;
			
		
				
		sum += (ll)*ss.begin();
		ss.erase(ss.begin());
			
		p--;
	}
	
	return sum <= (ll)s;
}

void restoreAns(int k)
{
	vector < int > need;
	
	for (int i = m-1; i >= 0; i -= k)
	{
		need.pb(a[i].fst);
	}
		
	reverse(need.begin(), need.end());
		
	int p = (int)need.size() - 1;
	
	int v = n-1;
	multiset < pair < int, int > > ss;
	vector < int > ans;
	
	
	
	for (;v >= 0 && p >= 0; v--)
	{
		if (b[v].fst.fst < need[p])
		{
			ans.pb((*ss.begin()).snd);
			ss.erase(ss.begin());
			
			p--;
			v++;
			continue;
		}
		
		
		ss.insert(mp(b[v].fst.snd, b[v].snd));
	}
	
	while (p >= 0)
	{
		ans.pb((*ss.begin()).snd);
		ss.erase(ss.begin());
			
		p--;
	}
	
	
	int pos = 0;
	vector < int > ans2;
	ans2.resize(m);
	int curr = 0;
	for (int i = m-1; i >= 0; i--)
	{
		if (curr == k)
		{
			pos++;
			curr = 0;
		}
		curr++;
			
			
		ans2[a[i].snd-1] = ans[pos];
		
	}
	
	for (int i = 0; i < m; i++)
	{
		if (i)
			printf(" ");
			
		printf("%d", ans2[i]);
	}
}

int main()
{
	//freopen("a.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &s);
	
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i].fst);
		
	for (int i = 0; i < m; i++)
		a[i].snd = i+1;
		
	for (int j = 0; j < n; j++)
		scanf("%d", &b[j].fst.fst);
		
	for (int j = 0; j < n; j++)
		scanf("%d", &b[j].fst.snd);
		
	for (int i = 0; i < n; i++)
		b[i].snd = i+1;
		
	sort(a, a + m);
	sort(b, b + n);
		
	int lo = 0, hi = m+1;
	

	while (hi - lo > 1)
	{
		int mid = (hi + lo) / 2;
		
		if (check(mid))
			hi = mid;
		else
			lo = mid;
	}
	
	if (hi == m+1)
	{
		puts("NO");
		return 0;
	}
	
	puts("YES");
	restoreAns(hi);
	
	
	
	return 0;
}