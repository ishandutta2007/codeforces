#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n, h;
	cin >> n >> h;
	
	double total = h / (2.);
	
	for(int i = 1;i < n;i++) {
		double curFrac = (i * total) / n;
		cout << fixed << setprecision(8);
		cout << sqrt(2 * h * curFrac) << " ";
	}
	
	cout << endl;
}