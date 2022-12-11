#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>

const double PI  =3.141592653589793238463;
using namespace std;

vector<int> rayons;

int main() {
	int nbRayons;
	cin >> nbRayons;
	
	double area = 0;
	for(int iRayon = 0;iRayon < nbRayons;iRayon++) {
		int rayon;
		cin >> rayon;
		rayons.push_back(rayon);
	}	
	
	sort(rayons.begin(), rayons.end());
	
	cout << fixed << setprecision(10);
	
	for(int iRayon = 0;iRayon < nbRayons;iRayon++) {
		int rayon = rayons[iRayon];
		if((nbRayons - iRayon) % 2 == 0) {
			area -= rayon * rayon * PI;
		}
		else {
			area += rayon * rayon * PI;
		}
	}
	
	cout << area << endl;
}