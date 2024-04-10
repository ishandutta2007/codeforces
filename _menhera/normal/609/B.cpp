#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N, M; cin >> N >> M;
	vector<int> V(M);
	for(int i=0; i<N; ++i)
	{
		int t; cin >> t;
		V[t-1]++;
	}
	long long ans = 0;
	for(int i=0; i<M; ++i)
		for(int j=0; j<i; ++j)
			ans += 1LL*V[i]*V[j];
	cout << ans << endl;
}