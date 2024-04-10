#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INFINI = 1000 * 1000 * 1000;

int h[100 * 1000];

int m[100 * 1000];
int M[100 * 1000];

int main()
{
	int nbC;
	cin >> nbC;
	
	for(int iC = 0;iC < nbC;iC++)
		cin  >> h[iC];
	
	int maxi = 0;
	for(int iC = 0;iC < nbC;iC++)
	{
		maxi = max(maxi, h[iC]);
		M[iC] = maxi;
	}
	
	int mini = INFINI;
	for(int iC = nbC - 1;iC >= 0;iC--)
	{
		m[iC] = mini;
		mini = min(mini, h[iC]);
	}
	
	int block = 0;
	for(int iC = 0;iC < nbC;iC++)
		if(M[iC] <= m[iC])
			block++;
	cout << block;
	return 0;
}