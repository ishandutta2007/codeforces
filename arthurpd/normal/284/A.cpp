#include <iostream>
#include <stdio.h>

int
main(void)
{
long long int p;
register bool check;
register long long int x, i, counter = 0, prev;
std:: cin >> p;
for(x = 1; x < p; x++)
	{
	prev = 1;
	check = true;
	for(i = 1; i <= p-2; i++, prev = (x % p) * (prev % p))
		if((((x % p) * (prev % p)) - 1) % p == 0)
			{
			check = false;
			break;
			}
	if(check == true && ((prev * x) - 1) % p == 0)
			counter++;
	}
std:: cout << counter << '\n';
return 0;
}