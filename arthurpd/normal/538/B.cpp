#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num;
int tab[1123456];

int pd(int n)
{
	if(n == 0)
		return 0;
	if(tab[n])
		return tab[n];
	int retv = 0x3f3f3f3f;
	for(int i = 0; i < num.size() && num[i] <= n; i++)
		retv = min(retv, pd(n - num[i]) + 1);
	return tab[n] = retv;
}

void print(int n)
{
	if(n == 0)
		return;
	for(int i = 0; i < num.size() && num[i] <= n; i++)
		if(tab[n] == tab[n - num[i]] + 1)
		{
			printf("%d\n", num[i]);
			print(n - num[i]);
			break;
		}
}

int
main(void)
{
	num.push_back(1);
	for(int j = 0; j < 128 && j < num.size(); j++)
	{
		num.push_back(10*num[j]);
		num.push_back(10*num[j]+1);
	}
	sort(num.begin(), num.end());
	int n;
	scanf("%d", &n);
	printf("%d\n", pd(n));
	print(n);
}