#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;
int n;
int gar, gay, c, m, l, x, y, t, pat, aa, k,i;
int a[2 * 100000 + 20]; int b[100050]; int h[100050]; int pata[100050];
char w;
pair <int, int>ar;
int main()
{
	cin >> n;
	cin >> t;
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 0; i < n; i++) 
	{		
		if (a[i] <= t)
		{
			x++;
 
		}
		else if (a[i] > t)
		{
			x = 0;
		}
		if (x == m )
		{
 
			pat++;
			x-= 1;
		}
	}
	cout <<  pat;
 
}