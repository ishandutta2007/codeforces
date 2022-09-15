#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int N, K;
		scanf("%d%d", &N, &K);
		if(N%K == 0) printf("1\n");
		else if(N >= K) printf("2\n");
		else printf("%d\n", (N+K-1)/N);
	}
}