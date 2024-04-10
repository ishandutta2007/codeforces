#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string>
using namespace std;

char num[1123456];
int n;

int rdm[7] = {1869,1968,1689,6198,1698,9861,1896};
int pot10[1123456];

void print()
{
	int x = 0, c = 0;
	bool check1 = true, check2= true, check3 = true, check4 = true;
	for(int i = 0; i < n; i++)
		if(num[i] == '1' && check1)
		{
			check1 = false;
			continue;
		}
		else if(num[i] == '6' && check2)
		{
			check2 = false;
			continue;
		}
		else if(num[i] == '8' && check3)
		{
			check3 = false;
			continue;
		}
		else if(num[i] == '9' && check4)
		{
			check4 = false;
			continue;
		}
		else
		{
			if(c == 0 && num[i] == '0')
			{
				swap(num[i], num[i+(rand()%(n-i))]);
				i--;
				continue;
			}
			x += (((int)(num[i]-'0')%7) * (pot10[n-c-1])) % 7;
//			printf("%d\n", pot10[n-);
			c++;
			printf("%c", num[i]);
			
		}
//	printf("\n%d\n", x);
	x= x%7;
	printf("%d\n", rdm[(7-x)%7]);
}
void print2()
{
	printf("%d", rdm[0]);
	for(int i = 0; i < n - 4; i++)
		printf("0");
	printf("\n");
}
int
main(void)
{
	scanf(" %s", num);
	n = strlen(num);
	pot10[0] = 1;
	for(int i = 1; i <= n; i++)
		pot10[i] = (pot10[i-1] * 10) % 7; 
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += num[i] - '0';
	sum -= 24;
	if(sum != 0 || (sum == 0 && n == 4))
		print();
	else
		print2();
	return 0;
}