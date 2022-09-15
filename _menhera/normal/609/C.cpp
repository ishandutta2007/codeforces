#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N; cin >> N;
	vector<int> V(N); int s = 0;
	for(int i=0; i<N; ++i)
	{
		cin >> V[i];
		s += V[i];
	}
	int lo = s / N, hi = (s+N-1)/N;
	int s1 = 0, s2 = 0;
	for(int i=0; i<N; ++i)
	{
		if(V[i] < lo) s1 += lo-V[i];
		if(V[i] > hi) s2 += V[i]-hi;
	}
	cout << max(s1, s2) << endl;
	return 0;
}