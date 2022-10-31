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

int ans[300005];

int main()
{
	//freopen("a.in", "r", stdin);
	int n;
	scanf("%d", &n);
	
	priority_queue < pair < ll, int > > q;
	
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		q.push(mp(-x, i));
	}
	
	ll curr = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (-q.top().fst > curr)
			curr = -q.top().fst;
			
		ans[q.top().snd] = curr;
		curr++;
		q.pop();
	}
	
	for (int i = 0; i < n; i++)
	{
		if (i)
			printf(" ");
		printf("%d", ans[i]);
	}
	
	
	return 0;
}