#include <cstdio>
#include <cstring>

using namespace std;

const int maxN = 100005;

char string[maxN], a[maxN], b[maxN];
int stringLength, aLength, bLength;

bool canSee (int start, int end, int direction)
{
	int aPos = 0, bPos = 0;

	for (int i = start; i != end; i += direction)
	{
		if (aPos >= aLength)
		{
			if (string[i] == b[bPos])
				bPos++;
			else
			{
				i -= direction * bPos;
				bPos = 0;
			}
		}
		else
		{
			if (string[i] == a[aPos])
				aPos++;
			else
			{
				i -= direction * aPos;
				aPos = 0;
			}
		}

		if (aPos >= aLength && bPos >= bLength)
			return true;
	}

	return false;
}

int main()
{
	scanf ("%s %s %s", string, a, b);
	stringLength = strlen (string);
	aLength = strlen (a);
	bLength = strlen (b);

	bool forward = canSee (0, stringLength, 1), backward = canSee (stringLength - 1, -1, -1);
	if (forward && backward) printf ("both\n");
	else if (forward) printf ("forward\n");
	else if (backward) printf ("backward\n");
	else printf ("fantasy\n");

	return 0;
}