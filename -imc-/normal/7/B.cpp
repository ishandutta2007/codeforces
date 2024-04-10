#include <cstdio>
#include <cstring>

using namespace std;

const int maxSize = 105;
int belongsTo[maxSize];
int memorySize;

void xdefragment()
{
	int pos = 0;
	for (int i = 0; i < memorySize; i++)
		if (belongsTo[i])
			belongsTo[pos++] = belongsTo[i];

	for (int i = pos; i < memorySize; i++) belongsTo[i] = 0;
}

int currentId = 0;

void xdump()
{
	for (int i = 0; i < memorySize; i++)
		printf ("%i ", belongsTo[i]);
	printf ("\n");
}

void xalloc (int size)
{
	for (int i = 0; i < memorySize; i++)
	{
		bool canAlloc = true;
		for (int j = 0; j < size; j++)
			if (i + j >= memorySize || belongsTo[i + j])
			{
				canAlloc = false;
				break;
			}

		if (!canAlloc) continue;

		currentId++;
		printf ("%i\n", currentId);

		for (int j = 0; j < size; j++)
			belongsTo[i + j] = currentId;

		return;
	}

	printf ("NULL\n");
}

void xerase (int id)
{
	bool erased = false;
	for (int i = 0; i < memorySize; i++)
		if (belongsTo[i] == id)
		{
			belongsTo[i] = 0;
			erased = true;
		}

	if (!erased || id == 0)
		printf ("ILLEGAL_ERASE_ARGUMENT\n");
}

int main()
{
	int nOps;
	scanf ("%i %i", &nOps, &memorySize);

	for (int i = 0; i < nOps; i++)
	{
		char command[256];
		scanf ("%s", command);

		if (!strcmp (command, "alloc"))
		{
			int argument;
			scanf ("%i", &argument);
			xalloc (argument);
		}
		else if (!strcmp (command, "erase"))
		{
			int argument;
			scanf ("%i", &argument);
			xerase (argument);
		}
		else xdefragment();

		//xdump();
	}

	return 0;
}