#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> q[112];
bool been[112][1123];
int tab[112][1123];

int pd(int h, int a)
{
	if(a == 0 || h == 100)
		return 0;
	if(been[h][a])
		return tab[h][a];
	been[h][a] = true;
	int s = 0, retv = pd(h+1, min(2*a, 1000));
	for(int i = 0; i < a && i < q[h].size(); i++)
	{
		s += q[h][i];
		retv = max(retv, pd(h+1, min((a - i - 1) * 2, 1000)) + s);
	}
	return tab[h][a] = retv;
}

int
main(void)
{
	int n, t, a, b;
	scanf("%d %d", &n, &t);
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		q[t-a].push_back(b);
	}
	for(int i = 0; i <= 100; i++)
		sort(q[i].rbegin(), q[i].rend());
	printf("%d\n", pd(0, 1));
}