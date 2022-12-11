#include <iostream>
using namespace std;

int main() {
	int nb;
	cin >> nb;
	
	int maxi = 0;
	int t = 0;
	int der = 0;
	for(int i = 0;i < nb;i++) {
		int v;
		cin >> v;
		if(v > der) {
			t++;
		}
		else {
			t = 1;
		}
		maxi = max(maxi, t);
		der = v;
	}
	
	cout << maxi << endl;
	return 0;
}