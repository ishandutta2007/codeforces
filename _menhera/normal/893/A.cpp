#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T; scanf("%d", &T);
	int spec = 3;
	while(T--)
	{
		int a; scanf("%d", &a);
		if(a==spec){puts("NO"); return 0;}
		spec = 6 - (a+spec);
	}
	puts("YES");
}