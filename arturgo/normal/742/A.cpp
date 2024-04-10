#include <iostream>
using namespace std;

int tab[4] = {6, 8, 4, 2};

int main() {
	int puis;
	cin >> puis;
	
	if(puis == 0)
		cout << 1 << endl;
	else
		cout << tab[puis % 4] << endl;
}