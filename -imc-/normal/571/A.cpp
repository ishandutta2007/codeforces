#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

ll solveBC_(int A, int b, int c, int l)
{
	//printf("%d %d %d %d\n", A, b, c, l);
	A = min(A, b + c + l);
	// n ways to make b + c <= A
	
	if (b + c > A) return 0;
	if (b + c == A) return 1;
	
	int x = A - b - c;
	
	ll nWays = (x + 1) * (ll)(x + 2) / 2;
	return nWays;
}
ll solveBC(int A, int b, int c, int l)
{
	ll nWays = solveBC_(A, b, c, l);
	//printf("n ways make %d + %d <= %d (%d add): %lld\n", b, c, A, l, nWays);
	return nWays;
}

void solve()
{
	int a, b, c, l;
	if (true)
	{
		scanf("%d %d %d %d", &a, &b, &c, &l);
	}
	else
	{
		a = rand() % 5 + 1;
		b = rand() % 5 + 1;
		c = rand() % 5 + 1;
		l = rand() % 5;
	}
	ll answer = 0;
	
	//printf("%d %d %d %d\n", a, b, c, l);
	
	for (int t = 0; t < 3; t++)
	{
		for (int addA = 0; addA <= l; addA++)
		{
			answer -= solveBC(a + addA, b, c, l - addA);
		}
		swap(a, b);
		swap(b, c);
	}
		
	ll nWays = (l + 3) * (ll)(l + 2) / 2 * (ll)(l + 1) / 3;
	//printf("nWays: %lld, forbidden: %lld\n", nWays, -answer);
	answer += nWays;
	cout << answer << endl;
	
	/*ll expected = 0;
	for (int aa = 0; aa <= l; aa++)
		for (int ab = 0; aa + ab <= l; ab++)
			for (int ac = 0; aa + ab + ac <= l; ac++)
			{
				if (a + aa >= b + ab + c + ac) continue;
				if (b + ab >= a + aa + c + ac) continue;
				if (c + ac >= a + aa + b + ab) continue;
				
				expected++;
			}
	
	printf("Expected %lld\n", expected);
	assert(answer == expected);*/
}

int main()
{
	//while (true) solve();
	
#ifdef LOCAL
	for (int i = 0; i < 4; i++)
#endif
	solve();
	
	return 0;
}