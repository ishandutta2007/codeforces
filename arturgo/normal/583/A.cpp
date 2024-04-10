#include <iostream>
using namespace std;

bool vuLig[100], vuCol[100];

int main() {
	int nbFois;
	cin >> nbFois;
	
	for(int iFois = 1;iFois <= nbFois * nbFois;iFois++) {
		int lig, col;
		cin >> lig >> col;
		
		if(!vuLig[lig] && !vuCol[col]) {
			cout << iFois << " ";
			vuLig[lig] = true;
			vuCol[col] = true;
		}
	}
	cout << endl;
	return 0;
}