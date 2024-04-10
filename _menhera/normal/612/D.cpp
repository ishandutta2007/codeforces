#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N, K; scanf("%d%d", &N, &K);
	vector<pair<int, int> > V;
	vector<int> ans;
	for(int i=0; i<N; ++i)
	{
		int a, b; scanf("%d%d", &a, &b);
		V.emplace_back(a, 0);
		V.emplace_back(b, 1);
	}
	sort(V.begin(), V.end());
	int p = 0;
	for(auto [i, v]: V)
	{
		if(v == 0)
		{
			if(++p == K) ans.push_back(i);
		}
		else
		{
			if(p-- == K) ans.push_back(i);
		}
	}
	printf("%d\n", (int)ans.size()/2);
	for(int i=0; i<(int)ans.size(); i+=2)
		printf("%d %d\n", ans[i], ans[i+1]);
}