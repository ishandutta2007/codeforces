#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <math.h>
using namespace std;


int main() 
{
	char a[6][2];
	string pat = "NO";
	cin >> a[0][0] >> a[0][1];
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i + 1][0] >> a[i + 1][1];
		if (a[i + 1][0] == a[0][0] || a[i + 1][1] == a[0][1])
		{
			pat = "YES";
		}
	}
	cout << pat;
	return 0;
}