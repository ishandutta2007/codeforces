#include <iostream>
using namespace std;

int main() {
	int nb;
	cin >> nb;
	
	int p[2] = {0, 0};
	
	for(int i = 0;i < nb;i++) {
		int a;
		cin >> a;
		p[a%2]++;
	}
	
	if(p[1] % 2 == 0)
		cout << p[0] << endl;
	else
		cout << p[1] << endl;
}