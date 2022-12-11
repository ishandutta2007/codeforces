#include <bits/stdc++.h>

const int maxn = 1000111;
int n;
char s[maxn];

int main(){
	scanf("%d%s", &n, s+1);
	int cnt = 0, sum = 0;
	for(int i=1; i<=n; i++)
	{
		int nsum = sum;
		if(s[i] == ')') nsum--;
		else nsum++;
		if(sum < 0 || nsum < 0) cnt++;
		sum = nsum;
	}
	if(sum) puts("-1");
	else printf("%d\n", cnt);
	return 0;
}