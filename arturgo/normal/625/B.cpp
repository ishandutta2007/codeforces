#include <iostream>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	
	int nbR = 0;
	for(int iCarA = 0;iCarA < (int)a.size();iCarA++) {
		bool egal = true;
		for(int iCarB = 0;iCarB < (int)b.size();iCarB++) {
			if(a[iCarA + iCarB] != b[iCarB]) {
				egal = false;
			}
		}
		if(egal) {
			nbR++;
			a[iCarA + (int)b.size() - 1] = '#';
		}
	}
	
	cout << nbR << endl;
	return 0;
}