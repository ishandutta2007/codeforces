#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int N, K;
		cin >> N >> K;
		vector<int> A(N);
		vector<long long> S(N);
		for (int &x : A)
			cin >> x;
		long long ans = 0;
		if(K >= N)
		{
			for(int x: A) ans += x, ans += K-1;
			ans -= (long long)N*(N-1)/2;
		}
		else
		{
			S[0] = A[0];
			for(int i=1; i<N; i++)
				S[i] = S[i-1] + A[i];
			ans = S[K-1];
			for(int i=K; i<N; i++)
				ans = max(ans, S[i] - S[i-K]);
			ans += (long long)K*(K-1)/2;
		}
		cout << ans << endl;
	}
}