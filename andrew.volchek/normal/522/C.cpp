#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cassert>
#include <set>
#include <vector>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define y1 asdkjghjasd
#define fst first
#define snd second
#define y0 sakjglajaa
#define ll long long
#define ull unsigned long long
#define ld long double

const int maxn = 100005;
int a[maxn];
int b[maxn];
int c[maxn], w[maxn];
int ans[maxn];

int main()
{
	//freopen("a.in", "r", stdin);
	int t;
	scanf("%d", &t);
	
	while (t--)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		n--;
		
		for (int i = 1; i <= k; i++)
		{
			scanf("%d", a + i), ans[i] = 0;
			b[i] = a[i];
		}
			
		for (int i = 0; i < n; i++)
			scanf("%d %d", c + i, w + i);
			
		vector < int > freeUnknowns;
			
		for (int iter = 0; iter < 2; iter++)
		{
			bool alreadyWorried = false;
			vector < int > unknown;
			
			for (int i = 0; i < n; i++)
			{
				if (w[i])
				{
					if (!alreadyWorried)
					{
						int freeUnknownsCnt = 0;
						for (int j = 0; j < freeUnknowns.size(); j++)
							if (freeUnknowns[j] < i)
								freeUnknownsCnt++;
								
						set < int > presentInRight;
						
						for (int j = i; j < n; j++)
							if (c[j])
								presentInRight.insert(c[j]);
								
						int bestCost = 1e9;
						int bestInd = 0;
						
						for (int j = 1; j <= k; j++)
						{
							if (!presentInRight.count(j))
							{
								if (a[j] < bestCost)
								{
									bestCost = a[j];
									bestInd = j;
								}
							}
						}
						
						for (int j = 1; j <= k; j++)
						{
							if (!presentInRight.count(j))
							{
								if (a[j] <= bestCost + freeUnknownsCnt)
								{
									ans[j] = 1;
								}
							}
						}
						
						while (a[bestInd])
						{
							unknown.pop_back();
							a[bestInd]--;
						}
					}
					
					alreadyWorried = true;
					
					if (c[i])
					{
						assert(a[c[i]] > 0);
						a[c[i]]--;
					}
					else
						unknown.pb(i);
				}
				else
				{
					if (c[i])
					{
						assert(a[c[i]] > 0);
						a[c[i]]--;
					}
					else
						unknown.pb(i);
				}
			}
			
			for (int i = 1; i <= k; i++)
			{
				if (a[i] <= (int)unknown.size())
					ans[i] = 1;
			}
			
			for (int i = 1; i <= k; i++)
				a[i] = b[i];
				
			freeUnknowns = unknown;
		}
		
		for (int i = 1; i <= k; i++)
			printf("%c", ans[i] ? 'Y' : 'N');
		printf("\n");
	}
	
	
	return 0;
}