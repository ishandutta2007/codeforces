#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N; scanf("%d", &N);
	for(int i=13; i>=0; --i)
	{
		int div = (1<<(2*i+1)) - (1<<i);
		if(N%div == 0)
		{
			printf("%d\n", div);
			return 0;
		}
	}
}