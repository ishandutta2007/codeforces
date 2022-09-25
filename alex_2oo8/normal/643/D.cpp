#include <bits/stdc++.h>
#define MAXN 100005

using namespace std;

static long long t[MAXN];
static int g[MAXN];
static int d[MAXN];
static long long prevsum[MAXN];

static pair<long long, multiset<long long>> prevsets[MAXN];

static multiset<long long> mins;
static multiset<long long> maxs;

long long getValue (int ind)
{
	long long res = prevsum[ind];
	res += t[ind] - (long long)(d[ind] + 1) * (t[ind] / (long long)(d[ind] + 2));
	res += t[g[ind]] / (long long)(d[g[ind]] + 2);
	return res;
}

long long getMin (pair<long long, multiset<long long>> *s)
{
	if (s->second.empty()) return 2000000000000000000LL;
	else return *(s->second.begin()) + s->first;
}

long long getMax (pair<long long, multiset<long long>> *s)
{
	if (s->second.empty()) return -1LL;
	else return *(s->second.rbegin()) + s->first;
}

int main ()
{
	int N, Q;
	scanf("%d %d",&N,&Q);
	int i;
	for (i = 0; i < N; i++)
	{
		scanf("%I64i",&t[i]);
	}
	memset(d,0,sizeof(d));
	memset(prevsum,0,sizeof(prevsum));
	for (i = 0; i < N; i++)
	{
		scanf("%d",&g[i]);
		g[i]--;
		d[g[i]]++;
	}
	for (i = 0; i < N; i++)
	{
		prevsum[g[i]] += t[i] / (long long)(d[i] + 2);
		prevsets[i].first = 0LL;
	}
	for (i = 0; i < N; i++)
	{
		prevsets[g[i]].second.insert(getValue(i));
	}
	for (i = 0; i < N; i++)
	{
		mins.insert(getMin(&prevsets[i]));
		maxs.insert(getMax(&prevsets[i]));
		//printf("%I64i %I64i\n",getMin(&prevsets[i]),getMax(&prevsets[i]));
	}
	int iQ;
	for (iQ = 0; iQ < Q; iQ++)
	{
		int T;
		scanf("%d",&T);
		if (T == 1)
		{
			int v, x, y;
			scanf("%d %d",&v,&y);
			v--; y--;
			x = g[v];

			//printf("OK 0\n");

			mins.erase(mins.find(getMin(&prevsets[g[g[x]]])));
			maxs.erase(maxs.find(getMax(&prevsets[g[g[x]]])));
			prevsets[g[g[x]]].second.erase(prevsets[g[g[x]]].second.find(getValue(g[x]) - prevsets[g[g[x]]].first));
			prevsum[g[x]] -= t[x] / (long long)(d[x] + 2);
			prevsets[g[g[x]]].second.insert(getValue(g[x]) - prevsets[g[g[x]]].first);
			mins.insert(getMin(&prevsets[g[g[x]]]));
			maxs.insert(getMax(&prevsets[g[g[x]]]));

			//printf("OK 1\n");

			mins.erase(mins.find(getMin(&prevsets[g[g[y]]])));
			maxs.erase(maxs.find(getMax(&prevsets[g[g[y]]])));
			prevsets[g[g[y]]].second.erase(prevsets[g[g[y]]].second.find(getValue(g[y]) - prevsets[g[g[y]]].first));
			prevsum[g[y]] -= t[y] / (long long)(d[y] + 2);
			prevsets[g[g[y]]].second.insert(getValue(g[y]) - prevsets[g[g[y]]].first);
			mins.insert(getMin(&prevsets[g[g[y]]]));
			maxs.insert(getMax(&prevsets[g[g[y]]]));

			//printf("OK 2\n");

			mins.erase(mins.find(getMin(&prevsets[x])));
			maxs.erase(maxs.find(getMax(&prevsets[x])));
			mins.erase(mins.find(getMin(&prevsets[y])));
			maxs.erase(maxs.find(getMax(&prevsets[y])));
			prevsets[g[v]].second.erase(prevsets[g[v]].second.find(getValue(v) - prevsets[g[v]].first));
			g[v] = y;
			prevsets[g[v]].second.insert(getValue(v) - prevsets[g[v]].first);
			mins.insert(getMin(&prevsets[x]));
			maxs.insert(getMax(&prevsets[x]));
			mins.insert(getMin(&prevsets[y]));
			maxs.insert(getMax(&prevsets[y]));

			//printf("OK 3\n");

			mins.erase(mins.find(getMin(&prevsets[x])));
			maxs.erase(maxs.find(getMax(&prevsets[x])));
			mins.erase(mins.find(getMin(&prevsets[g[x]])));
			maxs.erase(maxs.find(getMax(&prevsets[g[x]])));
			prevsets[g[x]].second.erase(prevsets[g[x]].second.find(getValue(x) - prevsets[g[x]].first));
			prevsets[x].first -= t[x] / (long long)(d[x] + 2);
			d[x]--;
			prevsets[x].first += t[x] / (long long)(d[x] + 2);
			prevsets[g[x]].second.insert(getValue(x) - prevsets[g[x]].first);
			mins.insert(getMin(&prevsets[x]));
			maxs.insert(getMax(&prevsets[x]));
			mins.insert(getMin(&prevsets[g[x]]));
			maxs.insert(getMax(&prevsets[g[x]]));

			//printf("OK 4\n");

			mins.erase(mins.find(getMin(&prevsets[y])));
			maxs.erase(maxs.find(getMax(&prevsets[y])));
			mins.erase(mins.find(getMin(&prevsets[g[y]])));
			maxs.erase(maxs.find(getMax(&prevsets[g[y]])));
			prevsets[g[y]].second.erase(prevsets[g[y]].second.find(getValue(y) - prevsets[g[y]].first));
			prevsets[y].first -= t[y] / (long long)(d[y] + 2);
			d[y]++;
			prevsets[y].first += t[y] / (long long)(d[y] + 2);
			prevsets[g[y]].second.insert(getValue(y) - prevsets[g[y]].first);
			mins.insert(getMin(&prevsets[y]));
			maxs.insert(getMax(&prevsets[y]));
			mins.insert(getMin(&prevsets[g[y]]));
			maxs.insert(getMax(&prevsets[g[y]]));

			//printf("OK 5\n");

			mins.erase(mins.find(getMin(&prevsets[g[x]])));
			maxs.erase(maxs.find(getMax(&prevsets[g[x]])));
			prevsets[g[x]].second.erase(prevsets[g[x]].second.find(getValue(x) - prevsets[g[x]].first));
			prevsum[x] -= t[v] / (long long)(d[v] + 2);
			prevsets[g[x]].second.insert(getValue(x) - prevsets[g[x]].first);
			mins.insert(getMin(&prevsets[g[x]]));
			maxs.insert(getMax(&prevsets[g[x]]));

			//printf("OK 6\n");

			mins.erase(mins.find(getMin(&prevsets[g[y]])));
			maxs.erase(maxs.find(getMax(&prevsets[g[y]])));
			prevsets[g[y]].second.erase(prevsets[g[y]].second.find(getValue(y) - prevsets[g[y]].first));
			prevsum[y] += t[v] / (long long)(d[v] + 2);
			prevsets[g[y]].second.insert(getValue(y) - prevsets[g[y]].first);
			mins.insert(getMin(&prevsets[g[y]]));
			maxs.insert(getMax(&prevsets[g[y]]));

			//printf("OK 7\n");

			mins.erase(mins.find(getMin(&prevsets[g[g[x]]])));
			maxs.erase(maxs.find(getMax(&prevsets[g[g[x]]])));
			prevsets[g[g[x]]].second.erase(prevsets[g[g[x]]].second.find(getValue(g[x]) - prevsets[g[g[x]]].first));
			prevsum[g[x]] += t[x] / (long long)(d[x] + 2);
			prevsets[g[g[x]]].second.insert(getValue(g[x]) - prevsets[g[g[x]]].first);
			mins.insert(getMin(&prevsets[g[g[x]]]));
			maxs.insert(getMax(&prevsets[g[g[x]]]));

			//printf("OK 8\n");

			mins.erase(mins.find(getMin(&prevsets[g[g[y]]])));
			maxs.erase(maxs.find(getMax(&prevsets[g[g[y]]])));
			prevsets[g[g[y]]].second.erase(prevsets[g[g[y]]].second.find(getValue(g[y]) - prevsets[g[g[y]]].first));
			prevsum[g[y]] += t[y] / (long long)(d[y] + 2);
			prevsets[g[g[y]]].second.insert(getValue(g[y]) - prevsets[g[g[y]]].first);
			mins.insert(getMin(&prevsets[g[g[y]]]));
			maxs.insert(getMax(&prevsets[g[g[y]]]));

			//printf("OK 9\n");
		}
		else if (T == 2)
		{
			int ind;
			scanf("%d",&ind);
			ind--;
			printf("%I64i\n",getValue(ind));
		}
		else
		{
			long long mn = *(mins.begin());
			long long mx = *(maxs.rbegin());
			printf("%I64i %I64i\n",mn,mx);
		}
	}
	return 0;	
}