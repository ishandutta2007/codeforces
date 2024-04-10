#include<bits/stdc++.h>
using namespace std;


long long find_lt(const vector<long long> &V, long long x)
{
	auto it = upper_bound(V.begin(), V.end(), x);
	if(it == V.begin()) return -1;
	return *prev(it);
}
long long find_gt(const vector<long long> &V, long long x)
{
	auto it = lower_bound(V.begin(), V.end(), x);
	if(it == V.end()) return -1;
	return *it;
}

long long solve()
{
	vector<long long> V[3];
	int m[3];
	for(int i=0; i<3; ++i) scanf("%d", m+i);
	for(int i=0; i<3; ++i)
	{
		for(int j=0; j<m[i]; ++j)
		{
			long long t;
			scanf("%lld", &t);
			V[i].push_back(t);
		}
		sort(V[i].begin(), V[i].end());
	}
	int pp[3] = {0, 1, 2};
	long long ans = 3e18;
	do
	{
		auto [a, b, c] = pp;
		for(auto Y: V[b])
		{
			long long X = find_lt(V[a], Y);
			if(X==-1) continue;
			long long Z = find_gt(V[c], Y);
			if(Z==-1) continue;
			ans = min(ans, (X-Y)*(X-Y)+(Y-Z)*(Y-Z)+(Z-X)*(Z-X));
		}
	} while (next_permutation(pp, pp+3));
	return ans;
}


int main()
{
	int T; scanf("%d", &T);
	while(T--)
		printf("%lld\n", solve());
}