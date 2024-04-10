#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <ctime>
#include <set>
#include <iomanip>
#include <ctime>
#define fr first
#define sc second
#define lli long long int
using namespace std;
int n, sum;
string sm[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };
string matx[5201];
char km;
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	/*for (int i = 0; i < n; i++)
	{
		cin >> matx[i];
	}*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n/4; j++)
		{
			cin >> km;
			if (km >= '0' && km <= '9')
				matx[i] += sm[km - '0'];
			else
				matx[i] += sm[km - 'A' + 10];

		}
	}
	int pat, k = 0, k1 = 0;
	bool fsm;
	for (pat = n; pat >= 1; pat--)
	{
		if (n%pat != 0)
			continue;
		k = 0;
		k1 = 0;
		fsm = true;
		while (k*pat!=n) 
		{
			sum = 0;
			for (int i = k * pat; i < (k + 1)*pat; i++)
			{
				for (int j = k1 * pat; j < (k1 + 1)*pat; j++)
				{
					sum += matx[i][j] - '0';
				}
			}
			if (!(sum == 0 || sum == pat * pat))
			{
				fsm = false;
				break;
			}
			k1++;
			if (k1*pat == n)
			{
				k1 = 0;
				k++;
			}
		}
		if (fsm)
		{
			cout << pat;
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << matx[i] << endl;
	}
	return 0;
}