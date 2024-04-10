#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	vector<char> stable(n);
	stable[0] = stable[n - 1] = true;
	for (int i = 1; i < n - 1; i++)
		if (a[i] == a[i - 1] || a[i] == a[i + 1])
			stable[i] = true;
		
	int answer = 0;
		
	for (int i = 0; i < n;)
	{
		if (stable[i])
		{
			i++;
			continue;
		}
		
		int j = i;
		while (!stable[j])
			j++;
		j--;
		
		//printf("%d..%d\n", i, j);
		
		if ((j - i + 1) % 2 == 0)
		{
			int t = (j - i + 1) / 2;
			answer = max(answer, t);
			assert(a[i - 1] != a[j + 1]);
			for (int k = 0; k < t; k++)
			{
				a[i + k] = a[i - 1];
				a[j - k] = a[j + 1];
			}
		}
		else
		{
			int t = (j - i + 2) / 2;
			answer = max(answer, t);
			assert(a[i - 1] == a[j + 1]);
			for (int k = i; k <= j; k++)
				a[k] = a[i - 1];
		}
		
		i = j + 1;
		continue;
	}
	
	printf("%d\n", answer);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}