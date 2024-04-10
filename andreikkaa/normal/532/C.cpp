/**
	inline void print_hello()
	{
		string message = R"(Hello!

		My name is Andrey E. Kalendarov,
		And I'm waiting for OK (or AC) status.

		Yes, please, don't blame my code.
		I know that it's far from ideal.
		But it should pass all the tests.

		And everybody will be happy.
		And you, my dear reader, too.
		I'm sure.

		Goodbye.)";

		cout << message << endl;
	}
**/

/* _____ INCLUDES _____ */

// ===== IO, STRINGS SECTION =====

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>

// ===== STL SECTION =====

#include <algorithm>
#include <array>
#include <list>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

// ===== OTHER LIBS SECTION =====

#include <math.h>
#include <stdlib.h> // RANDOM IS MY HOME!!!
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <memory.h>

/* _____ SPECIAL FEATURES _____ */

using namespace std;

/* _____ CODE _____ */

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	while(x1 + y1 != 0 and x2 + y2 != 0)
	{
		if(x1 <= x2 and y1 <= y2)
		{
			cout << "Polycarp" << endl;
			return 0;
		}

		if(x2 <= x1 and y2 <= y1)
		{
			cout << "Vasiliy" << endl;
			return 0;
		}

		if(y2 < y1)
		{
			--y1;
		}
		else
		{
			--x1;
		}

		if(x2 != 0 and y2 != 0)
		{
			--x2;
			--y2;
		}
		else
		{
			if(x2 == 0)
				--y2;
			else
				--x2;
		}
	}

	if(x1 + y1 == 0)
	{
		cout << "Polycarp" << endl;
		return 0;
	}
	else
	{
		cout << "Vasiliy" << endl;
		return 0;
	}

    return 0;
}