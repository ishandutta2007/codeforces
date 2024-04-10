#include <iostream>
using namespace std;

bool maj, inf, dig;

int main() {
	string pass;
	cin >> pass;
	
	if(pass.size() < 5) {
		cout << "Too weak" << endl;
		return 0;
	}
	
	for(char car : pass) {
		if(car >= '0' && car <= '9')
			dig = true;
		if(car >= 'A' && car <= 'Z')
			maj = true;
		if(car >= 'a' && car <= 'z')
			inf = true;
	}
	
	if(!maj || !inf || !dig) {
		cout << "Too weak" << endl;
		return 0;
	}
	
	cout << "Correct" << endl;
	return 0;
}