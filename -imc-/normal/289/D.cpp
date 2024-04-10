#include <cstdio>
#include <algorithm>

int first[10];
int until = 8;
bool reachable[10];
bool visited[10];
bool visiting[10];

bool dfs (int v)
{
	//printf ("%i: %i %i!\n", v, reachable[v], visited[v]);
	if (visiting[v]) return false;
	if (visited[v]) return reachable[v];
	visiting[v] = true;
	reachable[v] = (first[v] == 0) || dfs (first[v]);
	visiting[v] = false;
	visited[v] = true;
	//printf ("%i: %i %i!\n", v, reachable[v], visited[v]);
	return reachable[v];
}

int generate (int nPlaced)
{
	//printf ("gen %i\n", nPlaced);
	if (nPlaced == until)
	{
		//if (first[0] == 0) return 0;
		//printf ("Checking\n");

		for (int i = 0; i < nPlaced; i++) { visited[i] = visiting[i] = false; reachable[i] = false; }

		for (int i = 0; i < nPlaced; i++)
			if (!dfs (i)) return 0;

		//for (int i = 0; i < until; i++) printf ("%i ", first[i]); printf ("\n");

		return 1;
	}

	int answer = 0;
	for (int i = 0; i < until; i++)
	{
		first[nPlaced] = i;
		answer += generate (nPlaced + 1);
	}
	return answer;
}

const int f[9] = { -1, 1, 2, 9, 64, 625, 7776, 117649, 2097152 };

int main()
{
	/*for (until = 1; until <= 8; until++)
	{
		int x = generate (0);
		printf ("%i: %i variants\n", until, x);
	}
	return 0;
	until = 4;
	printf ("%i\n", generate (0));
	return 0;*/

	int n, k;
	scanf ("%i %i", &n, &k);

	long long answer = f[k];

	for (int i = 0; i < n - k; i++)
	{
		answer *= n - k;
		answer %= 1000000007;
	}
	printf ("%i\n", (int)answer);
	//return 0;


	return 0;
}