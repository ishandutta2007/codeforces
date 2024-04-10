#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		v.push_back(1);
		
		while (v.size() >= 2 && v.back() == v[v.size() - 2])
		{
			int x = v.back();
			v.pop_back();
			v.pop_back();
			v.push_back(x + 1);
		}
	}
	
	for (int x: v)
		printf("%d ", x);
	printf("\n");
	
	return 0;
}