#include <iostream>
using namespace std;

int main() {
	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	
	int dx, dy;
	cin >> dx >> dy;
	
	if((ax - bx) % dx != 0 || (ay - by) % dy != 0) {
		cout << "NO" << endl;
		return 0;
	}
	
	int nbX = (ax - bx) / dx;
	int nbY = (ay - by) / dy;
	
	if((nbX + nbY) % 2 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}