#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

vector<pair<long long, long double>> points;

int main() {
	long long nbDisques, rayon;
	cin >> nbDisques >> rayon;
	
	for(long long iDisque = 0;iDisque < nbDisques;iDisque++) {
		long long col;
		cin >> col;
		
		long double hauteur = rayon;
		for(pair<long long, long double> point : points) {
			if(abs(point.first - col) <= 2 * rayon) {
				long long dx = (point.first - col) * (point.first - col);
				long long hyp = 4 * rayon * rayon;
				
				long double nouv = point.second + sqrt(hyp - dx);
				hauteur = max(hauteur, nouv);
			}
		}
		
		cout << fixed << setprecision(10);
		cout << hauteur << " ";
		
		points.push_back({col, hauteur});
	}
	
	return 0;
}