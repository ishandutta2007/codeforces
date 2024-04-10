#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string>
using namespace std;

int cred[112];
int debt[112];

int
main(void)
{
	int n, m,a ,b, c;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		cred[b] += c;
		debt[a] += c;
	}
	for(int i = 1; i <= n; i++)
		debt[i] -= min(debt[i], cred[i]);
	int ans = 0;
	for(int i = 1; i<= n; i++)
		ans += debt[i];
	printf("%d\n", ans);
	return 0;
}