#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	int low = 0, high = 1e9;
	// low -> can't, high -> can
	
	while (low + 1 != high)
	{
		int mid = (low + high) / 2;
		
		int byTwo = mid / 2 - mid / 6, byThree = mid / 3 - mid / 6, bySix = mid / 6;
		
		int extraOne = max(n - byTwo, 0), extraTwo = max(m - byThree, 0);
		if (extraOne + extraTwo <= bySix)
			high = mid;
		else
			low = mid;
	}
	
	printf("%d\n", high);
	
	return 0;
}