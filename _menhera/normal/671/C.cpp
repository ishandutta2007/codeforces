#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int MAXN = 202020;
const int INF = 1e9;
vector<int> factor[MAXN];
int N;
int a[MAXN];
set<pair<int, int> > S, Srev;
long long ans = 0;

long long int del(int s, int e, bool r);

long long int add(int s, int e)
{
	S.insert(make_pair(s,e));
	Srev.insert(make_pair(e,s));
	return del(s, e, false);
}

long long int del(int s, int e,bool r = true)
{
	//printf("%d %d!\n",s, e);
	auto it2 = S.find(make_pair(s, e));
	auto it3 = it2;
	auto it1 = it2;
	it1--;
	it3++;
	long long int retval = 1LL* ( (it3->first) - (it2->first) ) * ( (it2->second) - (it1->second) );
	if(r)
	{
		S.erase(it2);
		Srev.erase(make_pair(e,s));
	}
	return retval;
}

void printSet()
{
	puts("printSet");
	for(auto x: S)
		printf("%d %d\n",x.first, x.second);
	for(auto x: Srev)
		printf("%d %d\n",x.second, x.first);
	puts("pSetEnd");
}



void put(int s, int e, int x)
{
	//printf("put: %d %d %d\n", s, e, x);
	auto it1 = S.upper_bound(make_pair(s-1, INF));
	--it1;
//	printf("--%d %d\n",it1->first, it1->second);
	if(it1->second >= e) return;
	auto it2rev = Srev.lower_bound(make_pair(e, INF));
//	printf("--%d %d\n", it2rev->second, it2rev->first);
	if(it2rev->second <= s) return;
	auto it2 = S.lower_bound(make_pair(it2rev->second, it2rev->first));
	//it1, it2 is the set
	long long area = 0;
	++it1;
	//printSet();
	//printf("---%d %d %d %d---\n",it1->first, it1->second, it2->first, it2->second);
	
	auto begin = it1;
	while(begin != it2)
	{
		int xx = begin->first;
		int yy = begin->second;
		++begin;
		area -= del(xx, yy);
	}	
	area += add(s, e);
	//printf("OK: %d %d %d\n",s,e,area);
	ans += area * x;
}
int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		scanf("%d", a+i);
		int j=1;
		for(j=1; j*j<a[i]; j++)
		{
			if( a[i]%j == 0 )
			{
				factor[j].push_back(i);
				factor[a[i]/j].push_back(i);
			}
		}
		if (j*j==a[i]) factor[j].push_back(i);
	}
	for(int i=1; i<MAXN; i++) sort(factor[i].begin(), factor[i].end());

	for(int i=-1; i<=N+1; i++)
	{
		S.insert(make_pair(i, i-1)); // s to e 
		Srev.insert(make_pair(i-1, i));
	}
	for(int i=MAXN; i>=1; i--)
	{
		if(factor[i].size()<2) continue;
		int aa = factor[i][0];
		int bb = factor[i][1];
		int cc = factor[i][factor[i].size()-2];
		int dd = factor[i][factor[i].size()-1];
		//printf("%d %d %d %d\n",aa, bb, cc, dd);
		put(aa+1, dd-1, i);
		put(bb+1, N-1, i);
		put(0, cc-1, i);
	}
	printf("%lld\n",ans);
}