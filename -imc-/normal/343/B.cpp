#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

const int maxN = 100500;
char buf[maxN];

bool solve (const char* buffer)
{
	int n = strlen (buffer);
	bool was[4];
	for (int i = 0; i < 4; i++)
		was[i] = false;

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int way = i % 2;
		int sign = buffer[i] == '-';

		sum += (way ^ sign) * -2 + 1;

		//printf ("%s %d of %d now %d\n", buffer, i, n, mask);
	}

	return sum == 0;
}

void printAnswer (bool b)
{
	printf (b ? "Yes\n" : "No\n");
}

void assertAnswer (const char* s, bool t)
{
	bool x = solve (s);
	//printf ("%s Expected: %d, answer: %d\n", s, t, x);
	assert (t == x);
}

int main()
{
	scanf ("%s", buf);
	assertAnswer ("-++-", true);
	assertAnswer ("+-", false);
	assertAnswer ("++", true);
	assertAnswer ("-", false);
	printAnswer (solve (buf));

	return 0;
}