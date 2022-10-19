#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
ll n, k;
int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%lld%lld", &n, &k);
		if (k%3ll)
		{
			if (n%3ll == 0) printf("Bob\n");
			else printf("Alice\n");
		}
		else
		{
			ll am = k/3;
			am = (am-1)*3ll + 4ll;
			if (n == 0) printf("Bob\n");
			else 
			{
				ll mod = n%am;
				if (mod == am-1 || mod == am-2 || mod == am-3) printf("Alice\n");
				else if (mod%3 == 1 || mod%3 == 2) printf("Alice\n");
				else printf("Bob\n");
			}
		}
	}
}