#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	
	string nombre;
	cin >> nombre;
	
	nombre = "00" + nombre;
	
	for(int iC1 = 0;iC1 < (int)nombre.size();iC1++) {
		for(int iC2 = iC1 + 1;iC2 < (int)nombre.size();iC2++) {
			for(int iC3 = iC2 + 1;iC3 < (int)nombre.size();iC3++) {
				int val = (nombre[iC1] - '0') * 100 + 
				(nombre[iC2] - '0') * 10 +
				(nombre[iC3] - '0') * 1;
				
				if(val % 8 == 0) {
					cout << "YES" << endl;
					cout << val << endl;
					return 0;
				}
			}
		}
	}
	
	cout << "NO" << endl;
	return 0;
}