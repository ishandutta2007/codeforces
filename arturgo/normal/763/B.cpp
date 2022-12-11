#include <iostream>
#include <vector>
using namespace std;

const int C = 1000 * 1000 * 1000;

int v[2][2] = {{1, 2}, {3, 4}};

int main() {
	int nbRectangles;
	cin >> nbRectangles;
	
	cout << "YES" << endl;
	
	for(int iRectangle = 0;iRectangle < nbRectangles;iRectangle++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		cout << v[(x1 + C) % 2][(y1 + C) % 2] << endl;
	}
	
	return 0;
}