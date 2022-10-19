#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int t;
	int n[10];
	int sqt[10];
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n[i];
		sqt[i] = sqrt(n[i]);
	}
	for (int i = 0; i < t; i++)
	{
		cout << 1 + sqt[i] * 2 - (sqt[i] == n[i] / sqt[i]) << endl;
		printf("0 ");
		for (int j = 1; j <= sqt[i]; j++)
			printf("%i ", j);
		if(sqt[i] != n[i] / sqt[i])
			printf("%i ", n[i] / sqt[i]);
		for (int j = sqt[i]-1; j >= 1; j--)
			printf("%i ", n[i]/j);
		printf("\n");
	}
}