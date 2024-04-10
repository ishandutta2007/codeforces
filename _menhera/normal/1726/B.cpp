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
		int N, M;
		cin >> N >> M;
		if (N % 2 == 1 && M - N + 1 > 0)
		{
			cout << "YES\n";
			for (int i = 0; i < N - 1; i++)
				cout << 1 << " ";
			cout << M - N + 1 << '\n';
		}
		else if ((N % 2 == 0 && M % 2 == 0) && M - N + 2 > 0)
		{
			cout << "YES\n";
			for (int i = 0; i < N - 2; i++)
				cout << 1 << " ";
			cout << (M - N + 2) / 2 << " " << (M - N + 2) / 2 << '\n';
		}
		else
			cout << "No\n";
	}
}