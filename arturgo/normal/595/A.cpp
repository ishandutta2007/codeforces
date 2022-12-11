#include <iostream>
using namespace std;

int main()
{
	int nbEtages, nbApparts;
	cin >> nbEtages >> nbApparts;
	
	int nbDebouts = 0;
	for(int iEtage = 0;iEtage < nbEtages;iEtage++)
		for(int iAppart = 0;iAppart < nbApparts;iAppart++)
		{
			int a, b;
			cin >> a >> b;
			if(a == 1 || b == 1)
				nbDebouts++;
		}
	cout << nbDebouts;
	return 0;
}