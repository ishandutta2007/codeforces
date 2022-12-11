#include <iostream>
using namespace std;

int main() {
	int nbCars;
	cin >> nbCars;
	
	string s;
	cin >> s;
	
	int a = 0;
	for(char car : s) {
		if(car == 'A')
			a++;
		else
			a--;
	}
	
	if(a > 0)
		cout << "Anton" << endl;
	else if(a < 0)
		cout << "Danik" << endl;
	else
		cout << "Friendship" << endl;
	return 0;
}