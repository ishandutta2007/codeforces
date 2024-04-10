#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) printf("%c",(i&1)?'1':'0');
	printf("\n");
	return 0;
}