#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int a[100100];

int main()
{
	int n;
	long long res = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; )
	{
		int j = i;
		while(j < n && a[i] == a[j]) j++;
		res += 1LL * (j-i) * (j-i+1) / 2;
		i = j;
	}
	cout << res << endl;
}