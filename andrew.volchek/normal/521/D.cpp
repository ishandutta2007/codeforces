#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
	return x * x;
}

const int maxn = 100005;

vector < pair < ll, int > > bestMults;
vector < pair < ll, int > > bestAdd[maxn];
pair < ll, int > bestSet[maxn];
int ptr[maxn];

ll a[maxn];
int tp[maxn];

ll currVal[maxn];


vector < pair < int, int > > hist;
void setPtr(int i, int val)
{
	hist.pb(mp(i, ptr[i]));
	ptr[i] = val;
}

int main()
{
	//srand(time(NULL));
	//gen();
	//freopen("a.in", "r", stdin);
	
	int k, n, m;
	scanf("%d %d %d", &k, &n, &m);
	
	for (int i = 1; i <= k; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = x;
	}
	
	for (int i = 1; i <= n; i++)
	{
		int type, ki, bi;
		scanf("%d %d %d", &type, &ki, &bi);
		
		tp[i] = type;
		
		if (type == 1)
		{
			bestSet[ki] = max(bestSet[ki], mp((ll)bi, i));
		}
		else if (type == 2)
		{
			bestAdd[ki].pb(mp(bi, i));
		}
		else
		{
			bestMults.pb(mp(bi, i));
		}
	}
	
	sort(bestMults.begin(), bestMults.end());
	reverse(bestMults.begin(), bestMults.end());
	
	for (int i = 1; i <= k; i++)
	{
		if (bestSet[i].fst > a[i])
		{
			bestAdd[i].pb(mp(bestSet[i].fst - a[i], bestSet[i].snd));
		}
		
		sort(bestAdd[i].begin(), bestAdd[i].end());
		reverse(bestAdd[i].begin(), bestAdd[i].end());
		
		ptr[i] = 0;
	}


	ld ans = -1e18;
	ld sum = 0;
	int bestMCnt = min(m, (int)bestMults.size());
	int bestHSize = 0;
	
	for (int i = 1; i <= k; i++)
	{
		currVal[i] = a[i];
		sum += log(a[i]);
	}
		
	
	for (int i = 0; i < min(m, (int)bestMults.size()); i++)
		sum += log(bestMults[i].fst);
		

	ans = sum;
	
	multiset < pair < ld, int > > q;
	
	for (int i = 1; i <= k; i++)
	{
		if (bestAdd[i].size())
		{
			q.insert(mp(/*-log(currVal[i]) + log(currVal[i] + bestAdd[i][0].fst)*/
			((ld)currVal[i] + bestAdd[i][0].fst) / currVal[i], i));
		}
	}
	
	int mCnt = bestMCnt;
	int currAdd = 0;
	
	while (true)
	{
		while (!q.empty() && mCnt + currAdd < m)
		{
			auto res = *q.rbegin();
			q.erase(res);
			
			//sum += res.fst;
			sum += -log(currVal[res.snd]) + log(currVal[res.snd] + bestAdd[res.snd][ptr[res.snd]].fst);
			currAdd++;
			
			currVal[res.snd] += bestAdd[res.snd][ptr[res.snd]].fst;
			setPtr(res.snd, ptr[res.snd] + 1);
			
			if (ptr[res.snd] < (int)bestAdd[res.snd].size())
			{
				q.insert(mp(/*-log(currVal[res.snd]) + log(currVal[res.snd] + bestAdd[res.snd][ptr[res.snd]].fst)*/
				((ld)currVal[res.snd] + bestAdd[res.snd][ptr[res.snd]].fst) / currVal[res.snd], res.snd));
			}
		}
		
		if (sum > ans)
		{
			ans = sum;
			bestMCnt = mCnt;
			bestHSize = hist.size();
		}
		
		if (mCnt == 0)
			break;
		
		sum -= log(bestMults[--mCnt].fst);
		
		
			
	}
	
	vector < int > ans2;
	
	while (hist.size() > bestHSize)
	{
		ptr[hist.back().fst] = hist.back().snd;
		hist.pop_back();
	}
	
	for (int i = 0; i < bestMCnt; i++)
		ans2.pb(bestMults[i].snd);
		
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < ptr[i]; j++)
			ans2.pb(bestAdd[i][j].snd);
	}
	
	sort(ans2.begin(), ans2.end(), [](int i, int j) { return tp[i] < tp[j]; } );
	
	printf("%d\n", (int)ans2.size());
	
	for (int i = 0; i < ans2.size(); i++)
	{
		if (i)
			printf(" ");
		printf("%d", ans2[i]);
	}
	
	
	return 0;
}