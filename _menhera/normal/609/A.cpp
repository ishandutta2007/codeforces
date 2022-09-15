#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N, M; cin >> N >> M;
	vector<int> V(N);
	for(int i=0; i<N; ++i) cin >> V[i];
	sort(V.rbegin(), V.rend());
	int s = 0;
	for(int i=0; i<N; ++i)
	{
		s += V[i];
		if(s >= M)
		{
			cout << i+1 << endl;
			return 0;
		}
	}
}