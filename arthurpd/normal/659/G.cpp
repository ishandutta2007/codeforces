#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define mod 1000000007LL

long long h[1123456];
int n;
long long tab[1123456][2];
bool been[1123456][2];

long long pd(int i, int k)
{
	if(i == n)
		return 0LL;
	if(been[i][k])
		return tab[i][k];
	been[i][k] = true;
	long long retv = 0;
	if(k == 0)
	{
		if(h[i+1] >= h[i])
			retv = (h[i] - 1) + (h[i]-1)*pd(i+1, 1) + pd(i+1, 0);
		else
			retv = (h[i] - 1) + (h[i+1] - 1)*pd(i+1, 1) + pd(i+1, 0);
	}
	else
	{
		if(h[i] > h[i-1] && h[i+1] >= h[i])
			retv = (h[i-1] - 1) + (h[i-1]-1)*pd(i+1, 1);
		else if(h[i] > h[i-1] && h[i+1] < h[i])
			retv = (h[i-1] - 1) + (min(h[i-1], h[i+1])-1)*pd(i+1, 1);
		else if(h[i+1] >= h[i])
			retv = (h[i] - 1) + (h[i]-1)*pd(i+1, 1);
		else
			retv = (h[i] - 1) + (h[i+1] - 1)*pd(i+1, 1);
	}
	return tab[i][k] = (retv % mod);
}

int
main(void)
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%lld", &h[i]);
	h[n] = 0x3f3f3f3f;
	printf("%I64d\n", pd(0, 0));
}