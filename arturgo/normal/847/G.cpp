#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> nbClasses(7, 0);

int main() {
	int nbGroupes;
	cin >> nbGroupes;
	
	for(int iGroupe = 0;iGroupe < nbGroupes;iGroupe++) {
		for(int iCar = 0;iCar < 7;iCar++) {
			char c;
			cin >> c;
			
			nbClasses[iCar] += c - '0';
		}
	}
	
	cout << *max_element(nbClasses.begin(), nbClasses.end()) << endl;
}