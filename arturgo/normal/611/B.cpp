#include <iostream>
using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	
	int count = 0;
	for(int nb0Av = 0;nb0Av < 62;nb0Av++) {
		for(int nb0Ap = 1;nb0Ap < 62 - nb0Av;nb0Ap++) {
			long long nb = (1ll << nb0Av) - 1 + (1ll << (nb0Av + 1)) * ((1ll << nb0Ap) - 1);
			
			if(nb >= a && nb <= b)
				count++;
		}
	}
	
	cout << count << endl;
	return 0;
}