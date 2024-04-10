#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 1;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<int> A(N);
		for (int &a : A)
			cin >> a;
		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			ans = max(ans, A[(i + N - 1) % N] - A[i]);
			ans = max(ans, A[N - 1] - A[i]);
			ans = max(ans, A[i] - A[0]);
		}
		cout << ans << endl;
	}
}