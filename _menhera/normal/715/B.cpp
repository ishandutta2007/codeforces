#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int u[101010];
int v[101010];
int w[101010];
int unk[101010];
vector<int> conn[101010];
int tp;
int N, M, L, s, t;
void setW(long long x)
{
	for(int i=0; i<tp; i++)
	{
		w[unk[i]] = (x+i)/tp;
	}
}

long long calc()
{
	vector<bool> visit(N, false);
	priority_queue<pair<long long, int> > Q;
	Q.emplace(-0, s);
	while(!Q.empty())
	{
		auto x = Q.top();
		Q.pop();
		auto dist = -x.first;
		auto a = x.second;
		if(visit[a]) continue;
		visit[a] = true;
		if(a==t) return dist;
		for(const auto& y: conn[a])
		{
			int tg = u[y]^v[y]^a;
			Q.emplace(-(dist+w[y]), tg);
		}
	}
	return -1;
}

void printE()
{
	puts("YES");
	for(int i=0; i<M; i++)
		printf("%d %d %d\n",u[i],v[i],w[i]);
	
}


int main()
{
	scanf("%d%d%d%d%d",&N,&M,&L,&s,&t);
	for(int i=0; i<M; i++)
	{
		scanf("%d%d%d",u+i,v+i,w+i);
		if(!w[i])
			unk[tp++] = i;
		conn[u[i]].push_back(i);
		conn[v[i]].push_back(i);
	}
	setW(tp);
	long long midst = calc();
	
	if(midst > L)
	{
		puts("NO");
		return 0;
	}
	if(midst == L)
	{
		printE();
		return 0;
	}
	
	setW(1LL*tp*(L+1));
	long long madst = calc();
	
	if(madst < L)
	{
		puts("NO");
		return 0;
	}
	if(madst == L)
	{
		printE();
		return 0;
	}
	
	long long lo = tp;
	long long hi = 1LL*tp*(L+1);
	while(lo+1!=hi)
	{
		long long mi = (lo+hi)/2;
		setW(mi);
		long long ans = calc();
		if(ans<L) lo = mi;
		else if(ans>L) hi = mi;
		else
		{
			printE();
			return 0;
		}
	}
	setW(lo);
	printE();
	return 0;
}