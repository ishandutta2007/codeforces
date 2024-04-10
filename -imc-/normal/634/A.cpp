#include <bits/stdc++.h>

using namespace std;

vector<int> read(int n)
{
	vector<int> a;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		if (x == 0) continue;
		a.push_back(x);
	}
	
	for (int i = 0; i < n; i++)
		if (a[i] == 1)
		{
			vector<int> b(n - 1);
			for (int j = 0; j < n - 1; j++)
				b[j] = a[(i + j) % (n - 1)];
			return b;
		}
		
	assert(!"impossible");
}

int main()
{
	int n;
	scanf("%d", &n);
	
	vector<int> a = read(n), b = read(n);
	printf("%s\n", a == b ? "YES" : "NO");
	
	return 0;
}