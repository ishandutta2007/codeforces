#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int n;
	scanf("%d", &n);
	
	vector<ll> w(1e6 + 1000);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		w[x]++;
	}
	
	int answer = 0;
	for (int i = 0; i < (int)w.size() - 1; i++)
	{
		w[i + 1] += w[i] / 2;
		w[i] %= 2;
		
		if (w[i] % 2 == 1)
			answer++;
	}
	
	printf("%d\n", answer);
	
	return 0;
}