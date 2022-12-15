#include <stdio.h>

typedef long long ll;

ll n, k;

int main()
{
	scanf("%lld %lld", &n, &k);
	long long a = 1;
	ll cnt = 1;
	while (a < k) {
		a = a * 2 + 1;
		cnt++;
	}
	
	if (k % 2) printf("1\n");
	else
	{
		ll ep = (a + 1) / 2;
		ll mp = (ep + 1) / 2;
		k /= 2;
		if (k % 2) printf("2\n");
		else
		{
			ll num = cnt;
			if (k > mp) k = (ep - k);

			while (true) {
				if (mp == k){
					printf("%lld\n", num);
					break;
				}
				ep = mp;
				mp /= 2;
				if (k > mp) k = (ep - k);

				num--;
			}
		}
	}

	return 0;
}