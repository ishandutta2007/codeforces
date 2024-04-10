#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N; scanf("%d", &N);
	vector<int> V(N+1), ans(N+1);
	map<int, vector<int> > M;
	for(int i=1; i<=N; ++i) scanf("%d", &V[i]);
	for(int s=1; s<=N; ++s)
	{
		if(V[s] == 0) continue;

		int p = s; vector<int> perm;
		while(V[p] != 0)
		{
			perm.push_back(p);
			int np = V[p]; V[p] = 0; p = np;
		}
		int K = perm.size();
		if(K%2==1)
		{
			for(int i=0; i<K; ++i)
			{
				int p = perm[1LL*i*(K+1)/2%K], q = perm[1LL*(i+1)*(K+1)/2%K];
				ans[p] = q;
			}
		}
		else
		{
			if(M.count(K))
			{
				vector<int> perm2 = M[K]; M.erase(K);
				for(int i=0; i<K; ++i)
				{
					int p = perm[i], q = perm2[i];
					ans[p] = q;
					p = perm2[i], q = perm[(i+1)%K];
					ans[p] = q;
				}
			}
			else M[K] = perm;
		}
	}
	if(M.size()) puts("-1");
	else
	{
		for(int i=1; i<=N; ++i)
			printf("%d ", ans[i]);
		puts("");
	}

}