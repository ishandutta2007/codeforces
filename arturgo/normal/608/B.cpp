#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

long long int nb[2][400 * 1000];
long long int cur[2][400 * 1000];

int main()
{
	string a, b;
	cin >> a >> b;
	
	for(int iCar = 0;iCar < (int)a.size();iCar++)
	{
		if(a[iCar] == '0')
			nb[0][iCar]++;
		else
			nb[1][iCar]++;
	}
		
	int reste = b.size() - a.size() + 1;
	int decal = 0;
	
	for(int iPuis = 0;iPuis <= 17;iPuis++)
	{
		if(reste % 2 == 1)
		{
			for(int iCar = 0;iCar < 400 * 1000 - decal;iCar++)
			{
				cur[0][iCar + decal] += nb[0][iCar];
				cur[1][iCar + decal] += nb[1][iCar];
			}
			decal += (1 << iPuis);
		}
		reste /= 2;
		
		long long int tmp[2][400 * 1000];
		for(int iCar = 0;iCar < 400 * 1000;iCar++)
			tmp[0][iCar] = tmp[1][iCar] = 0;
		
		for(int iCar = 0;iCar < 400 * 1000 - (1 << iPuis);iCar++)
		{
			tmp[0][iCar] += nb[0][iCar];
			tmp[1][iCar] += nb[1][iCar];
			tmp[0][iCar + (1 << iPuis)] += nb[0][iCar];
			tmp[1][iCar + (1 << iPuis)] += nb[1][iCar];
		}
				
		for(int iCar = 0;iCar < 400 * 1000;iCar++)
		{
			nb[0][iCar] = tmp[0][iCar];
			nb[1][iCar] = tmp[1][iCar];
		}
	}
	
	long long int diff = 0;
	for(int iCar = 0;iCar < (int)b.size();iCar++)
		if(b[iCar] == '0')
			diff += cur[1][iCar];
		else
			diff += cur[0][iCar];
	cout << diff;
	return 0;
}