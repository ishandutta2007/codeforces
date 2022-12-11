#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <list>
#include <cmath>
using namespace std;

string t[8];

int main()
{
	for(int i = 0;i < 8;i++)
		cin >> t[i];
	int melA = 8, melB = 8;
	for(int i = 0;i < 8;i++)
	{
		int pre = 0;
		for(int j = 0;j < 8;j++)
			if(pre == 0 && t[j][i] == 'W')
			{
				pre = 1;
				melA = min(melA,j);
			}
			else if(pre == 0 && t[j][i] == 'B')
				pre = 1;
		
		int der = 0;
		for(int j = 7;j >= 0;j--)
			if(der == 0 && t[j][i] == 'B')
			{
				der = 1;
				melB = min(melB, 7 - j);
			}
			else if(der == 0 && t[j][i] == 'W')
				der = 1;
	}
	if(melA <= melB)
		cout << "A" << endl;
	else
		cout << "B" << endl;
	return 0;
}