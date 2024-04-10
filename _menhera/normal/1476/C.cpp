#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int N;
		scanf("%d", &N);
		vector<int> C(N), A(N+1), B(N+1);
		for(int i=0; i<N; ++i) scanf("%d", &C[i]);
		for(int i=0; i<N; ++i) scanf("%d", &A[i]);
		for(int i=0; i<N; ++i) scanf("%d", &B[i]);


		long long maxv = 0;
		long long ans = 2 + abs(A[1]-B[1]);
		for(int i=1; i<N; ++i)
		{
			maxv = max(maxv, ans + C[i]-1);
			if(A[i+1] == B[i+1])
				ans = 2;
			else
			{
				ans += 2 + (C[i]-1) - abs(A[i+1]-B[i+1]);
				ans = max(ans, 2+(long long)abs(A[i+1]-B[i+1]));
			}
		}
		printf("%lld\n", maxv);
	}
}