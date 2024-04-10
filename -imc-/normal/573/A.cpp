#include <stdio.h>
#include <assert.h>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		while (a[i] % 2 == 0) a[i] /= 2;
		while (a[i] % 3 == 0) a[i] /= 3;
	}
	
	bool answer = true;
	for (int i = 0; i < n; i++)
		if (a[i] != a[0])
			answer = false;
	
	printf("%s\n", answer ? "Yes" : "No");
		
	return 0;
}