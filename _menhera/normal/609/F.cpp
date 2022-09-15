#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;

long long L[MAXN], R[MAXN];
int X[MAXN], T[MAXN];
int C[MAXN], N, M;
vector<pair<int, int> > V;

int idx(int pos){
	return lower_bound(V.begin(), V.end(), make_pair(pos, -1))->second;
}

set<pair<long long, long long> > LR, RL;

int incr(int pos, int len)
{
	auto it = RL.lower_bound(make_pair((long long)pos, -1LL));
	if(it == RL.end()) return -1;
	int ind = idx(it->second);
	if(pos<L[ind]) return -1;

	assert(L[ind] <= pos && pos <= R[ind]);

	C[ind]++;

	if(len == 0) return ind;

	auto it2 = LR.find(make_pair(L[ind], R[ind])); assert(it2 != LR.end());
	for(auto it3 = next(it); it3 != RL.end() && it3->first <= R[ind]+len;)
	{
		assert(LR.erase(make_pair(it3->second, it3->first)));
		assert(it3 != RL.end()); RL.erase(it3++);
	}

	assert(it != RL.end()); RL.erase(it); assert(it2 != LR.end()); LR.erase(it2);
	R[ind] += len;
	RL.emplace(R[ind], L[ind]); LR.emplace(L[ind], R[ind]);
	return ind;
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; ++i)
	{
		scanf("%d%d", X+i, T+i);
		V.emplace_back(X[i], i);
		LR.emplace(X[i], X[i]);
		RL.emplace(X[i], X[i]);
		L[i] = R[i] = X[i];
	}
	sort(V.begin(), V.end());

	for(int i=N-1; i>=0; --i)
	{
		auto [l, idx] = V[i];
		assert(idx == incr(l, T[idx]));
	}

	multiset<pair<long long, long long> > mosq;

	for(int i=0; i<M; ++i)
	{
		int p, b; scanf("%d%d", &p, &b);
		int res = incr(p, b);
		if(res == -1) mosq.emplace(p, b);
		else
			for(
				auto it = mosq.lower_bound(make_pair(L[res], -1LL));
				it != mosq.end() && it->first <= R[res];
				mosq.erase(it++)
			)
				assert(res == incr(it->first, it->second));
	}

	for(int i=0; i<N; ++i)
		printf("%d %lld\n", C[i]-1, R[i]-L[i]);
}