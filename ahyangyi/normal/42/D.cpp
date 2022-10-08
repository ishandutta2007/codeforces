#include <stdio.h>
#include <set>

using namespace std;

int data[20];
set<int> S;

bool check (int pos, int x)
{
	for (int i = 0; i < pos; i ++)
		if (S.find(x + data[i]) != S.end())
			return false;
	return true;
}

int main ()
{
	int n;

	scanf ("%d", &n);

	data[0] = 1; data[1] = 2;
	S.insert(3);

	for (int i = 2; i < n; i ++)
	{
		data[i] = data[i - 1] + 1;
		while (!check(i, data[i]))
			data[i] ++;
		for (int j = 0; j < i; j ++)
			S.insert(data[j] + data[i]);
	}
	
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
		{
			if (i == j)
				printf ("0");
			else
				printf ("%d", data[i] + data[j]);
			if (j < n - 1)
				printf (" ");
			else
				printf ("\n");
		}

	return 0;
}