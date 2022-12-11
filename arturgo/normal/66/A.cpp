#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <queue>
using namespace std;

bool comp(string a, string b) {
	if(a.size() == b.size()) {
		for(int iCar = 0;iCar < (int)a.size();iCar++) {
			if(a[iCar] != b[iCar]) {
				return a[iCar] < b[iCar];
			}
		}
		return true;
	}
	return a.size() < b.size();
}

int main() {
	string nombre;
	cin >> nombre;
	
	if(comp(nombre, "127")) {
		cout << "byte" << endl;
	}
	else if(comp(nombre, "32767")) {
		cout << "short" << endl;
	}
	else if(comp(nombre, "2147483647")) {
		cout << "int" << endl;
	}
	else if(comp(nombre, "9223372036854775807")) {
		cout << "long" << endl;
	}
	else {
		cout << "BigInteger" << endl;
	}
	return 0;
}