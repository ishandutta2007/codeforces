#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	if (min(m, k) >= n) printf("Yes\n");
	else printf("No\n");
}