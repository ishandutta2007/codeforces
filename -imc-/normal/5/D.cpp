#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cmath>

using namespace std;

typedef long double ftype;

ftype a, vMax, vPenalty, length, penaltyPosition;

pair <ftype, ftype> getTravelled (ftype t)
{
	if (vMax <= vPenalty)
	{
		ftype free = vMax / a;
		if (free > t)
			return make_pair (a * t * t / 2, a * t);
		else
			return make_pair (a * free * free / 2 + (t - free) * vMax, vMax);
	}
	else if (a * t <= vPenalty)
	{
		return make_pair (a * t * t / 2, a * t);
	}
	else
	{
		ftype tSwitch = vPenalty / (2 * a) + t / 2;
		assert (tSwitch >= 0 && tSwitch <= t);

		if (a * tSwitch > vMax)
		{
			ftype first = vMax / a, second = (vPenalty - vMax) / a + t;
			return make_pair (a * first * first / 2 + (second - first) * vMax + (t - second) * (vMax + vPenalty) / 2, vPenalty);
		}
		else
		{
			return make_pair (a * tSwitch * tSwitch / 2 + (t - tSwitch) * (a * tSwitch + vPenalty) / 2, vPenalty);
		}
	}
}

int main()
{
	cin >> a >> vMax >> length >> penaltyPosition >> vPenalty;

	ftype minTime = 0, maxTime = 1000000000;

	//int its = 0;
	while (true)
	{
		//if (its++ > 100) break;
		ftype middle = (minTime + maxTime) / 2;

		pair <ftype, ftype> solve = getTravelled (middle);

		//printf ("%Lf: %Lf\n", middle, solve.first);

		if (fabsl (solve.first - penaltyPosition) < 0.0000001) break;

		if (solve.first > penaltyPosition)
			maxTime = middle;
		else
			minTime = middle;
	}

	pair <ftype, ftype> solve = getTravelled (minTime);

	ftype C = penaltyPosition - length, B = solve.second, A = a / 2;

	ftype noLimit = (-B + sqrtl (B * B - 4 * A * C)) / (2 * A);

	ftype answer = 0;
	if (solve.second + noLimit * a <= vMax)
	{
		answer = minTime + noLimit;
	}
	else
	{
		ftype accelerate = (vMax - solve.second) / a;
		answer = minTime + accelerate + (length - penaltyPosition - a * accelerate * accelerate / 2 - solve.second * accelerate) / vMax;
	}

	cout << std::fixed << std::setprecision (6) << answer << endl;

	return 0;
}