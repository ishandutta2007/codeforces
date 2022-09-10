#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
char a[N];

bool ok(int t)
{
	vector<int> gwiazdki; int pozycja = 0;
	for (int i = 0; i < n; ++ i)
		if (a[i] == '*')
			gwiazdki.push_back(i);
	if (gwiazdki.empty()) return 1;
	for (int i = 0; i < n; ++ i)
	{
		if (a[i] == 'P') if (pozycja != gwiazdki.size())
		{
			if (gwiazdki[pozycja] > i)
			{
				while (pozycja < gwiazdki.size() && gwiazdki[pozycja] <= i + t)
				{
					pozycja ++;
				}
			}
			else
			{
				int x = i - gwiazdki[pozycja];
				if (gwiazdki[pozycja] < i - t) return 0;
				
				int y = max(t - 2*x,  (t - x)/2);					
				while (pozycja < gwiazdki.size() && gwiazdki[pozycja] <= i + y)
				{
					pozycja ++;
				}
			}		
		}
	}
	if (pozycja == (int) gwiazdki.size())
		return 1;
	else
		return 0;
}

int bin_s(int p, int k)
{
	if (k - p <= 5)
	{
		for (int i = p; i <= k; ++ i)
			if (ok(i))
				return i;
		return k;
	}
	int s = (p + k) / 2;
	if (ok(s))
		return bin_s(p, s);
	else
		return bin_s(s+1, k);
}

int main()
{
	scanf("%d%s", &n, a);
	printf("%d\n", bin_s(0, 2*n+2));
	return 0;
}