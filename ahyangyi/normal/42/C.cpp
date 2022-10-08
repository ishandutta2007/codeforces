#include <stdio.h>
#include <assert.h>

int data[4];

void div (int x)
{
	printf ("/%d\n", x % 4 + 1);

	assert (data[x % 4] % 2 == 0);
	assert (data[(x + 1) % 4] % 2 == 0);

	data[x % 4] /= 2;
	data[(x + 1) % 4] /= 2;
}

void inc (int x)
{
	printf ("+%d\n", x % 4 + 1);

	data[x % 4] ++;
	data[(x + 1) % 4] ++;
}

int get_binary_form (int x)
{
	return ((data[x % 4] & 1) << 3) + ((data[(x + 1) % 4] & 1) << 2) + ((data[(x + 2) % 4] & 1) << 1) + ((data[(x + 3) % 4] & 1) << 0);
}

int get_largest ()
{
	int max = 0, re = 0;

	for (int i = 0; i < 4; i ++)
		if (data[i] > max)
		{
			max = data[i];
			re = i;
		}

	return re;
}

int main ()
{
	for (int i = 0; i < 4; i ++)
		scanf ("%d", data + i);

	int l;
	while (l = get_largest(), data[l] > 1)
	{
//		printf ("x = %d\n", get_binary_form(l));
		switch (get_binary_form(l))
		{
		case 0:
		case 1:
		case 2:
		case 3:
			div(l);
			break;
		case 4:
		case 6:
			div(l + 3);
			break;
		case 5:
			inc(l + 1);
			inc(l + 2);
			div(l);
			div(l + 2);
			break;
		case 7:
			if (data[l] % 4 == 0)
			{
				inc(l + 1);
				inc(l + 2);
				div(l);
				div(l + 3);
			}
			else
			{
				inc(l);
				inc(l + 3);
				div(l);
				div(l + 3);
			}
			break;
		case 8:
		case 10:
			inc(l);
			div(l + 3);
			break;
		case 9:
		case 11:
		case 13:
		case 15:
			inc(l + 3);
			div(l + 3);
			break;
		case 12:
		case 14:
			inc(l);
			div(l);
			break;
		}
	}

	return 0;
}