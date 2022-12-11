#include <iostream>

using namespace std;



int main() {
   	int minR = -1000 * 1000 * 1000, maxR = 1000 * 1000 * 1000;
   	
   	int nb;
   	cin >> nb;
   	
   	for(int i = 0;i < nb;i++) {
   		int p, d;
   		cin >> p >> d;
   		
   		if(d == 1) {
   			minR = max(minR, 1900);
   		}
   		else {
			maxR = min(maxR, 1900);
		}
		
		minR += p;
		maxR += p;
	}
	
	if(maxR >= 500 * 1000 * 1000) {
		cout << "Infinity" << endl;
	}
	else if(minR >= maxR) {
		cout << "Impossible" << endl;
	}
	else {
		cout << maxR - 1 << endl;
	}
    return 0;
}