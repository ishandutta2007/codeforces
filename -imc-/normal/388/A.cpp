#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

int main()
{
	int nBoxes;
	scanf("%d", &nBoxes);
	
	vector<int> d(nBoxes);
	
	for (int i = 0; i < nBoxes; i++)
		scanf("%d", &d[i]);
	
	vector<bool> taken(nBoxes);
	int nTaken = 0, answer = 0;

	while(nTaken != nBoxes)
	{
		int needAtLeast = 0;
		while (true)
		{
			int best = -1;
			for (int j = 0; j < nBoxes; j++)
				if (!taken[j] && (d[j] >= needAtLeast) && (best == -1 || d[j] < d[best]))
					best = j;
					
			if (best != -1)
			{
				taken[best] = true;
				nTaken++;
				needAtLeast++;
			}
			else break;
		}
		
		answer++;
	}
	
	printf("%d\n", answer);
	
	return 0;
}