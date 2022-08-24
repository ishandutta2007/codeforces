#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int w[500100], n, i, pv, R;
bool ck[500100];
int main()
{
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", &w[i]);
	sort(w, w + n);
	for (i = 0; i < n; i++){
		while (w[pv] * 2 <= w[i])pv++;
		if (R < pv)R++;
	}
	if (R>n / 2)R = n / 2;
	printf("%d\n", n-R);
}