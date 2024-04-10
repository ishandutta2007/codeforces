#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

typedef long long ll;

int main()
{
	ll A, B, C;
	cin >> A >> B >> C;

	ll sA = A, sB = B, sC = C;

	if (C < 0)
	{
		A *= -1;
		B *= -1;
		C *= -1;
	}

	ll multX = 1, multY = 1;

	if (A < 0) { multX *= -1; A *= -1; }
	if (B < 0) { multY *= -1; B *= -1; }

	bool swapXY = false;

	if (A > B) { swap (A, B); swapXY = true; }

	/* ... */

 	ll rest = A, second = B;
	ll restA = 1, restB = 0;
	ll secondA = 0, secondB = 1;

	if (A)
	{
		while (true)
		{
			ll newRest = second % rest, newSecond = rest;
			if (newRest == 0) break;

			ll q = second / rest;

			ll newSecondA = restA, newSecondB = restB;
			restA = secondA - q * restA;
			restB = secondB - q * restB;

			rest = newRest;
			second = newSecond;
			secondA = newSecondA;
			secondB = newSecondB;
		}
	}
	else
	{
		rest = B;
		restA = 0;
		restB = 1;
	}

	if (C % rest != 0)
	{
		cout << -1 << endl;
		return 0;
	}

	C /= rest;
	ll x = -restA * C, y = -restB * C;

	//printf ("gcd %lld = %lld * %lld + %lld * %lld\n", rest, A, restA, B, restB);

	/* ... */

	if (swapXY) swap (x, y);

	x *= multX;
	y *= multY;

	//assert (sA * x + sB * y + sC == 0);

	cout << x << " " << y << endl;

	return 0;
}