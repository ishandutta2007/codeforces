#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int numUsers = 0, answer = 0;
	while (true)
	{
		char query[1000];
		if (scanf ("%[^\n] ", query) != 1) break;

		if (query[0] == '+')
			numUsers++;
		else if (query[0] == '-')
			numUsers--;
		else
			answer += (strlen (query) - (strchr (query, ':') - query) - 1) * numUsers;
	}

	printf ("%i\n", answer);

	return 0;
}