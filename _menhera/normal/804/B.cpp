#include<bits/stdc++.h>
using namespace std;
char str[1010101];
int main()
{
	const int MOD = 1e9+7;
	scanf("%s",str);
	int N = strlen(str);
	long long bcnt = 0;
	long long ans = 0;
	for(int i=N-1; i>=0; --i)
	{
		if(str[i]=='b') ++bcnt;
		else
		{
			ans += bcnt;
			bcnt *= 2;
			bcnt %= MOD;
		}
		bcnt %= MOD;
		ans %= MOD;
	}
	printf("%lld\n",ans%MOD);
}