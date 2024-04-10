#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main()
{
	ll a, b;
	cin >> a >> b;
	
	int answer = 0;
	for (int length = 2; length <= 64; length++)
	{
		for (int zero = 0; zero < length - 1; zero++)
		{
			ll num = 0;
			for (int i = 0; i < length; i++)
				if (i != zero)
					num += (1ULL << i);
				
			if (num >= a && num <= b)
			{
				//printf("%d\n", num);
				answer++;
			}
		}
	}
	
	printf("%d\n", answer);
	
	return 0;
}