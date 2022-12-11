#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int nbTests;
	cin >> nbTests;
	
	for(int iTest = 0;iTest < nbTests;iTest++) {
		int nbElems, d;
		cin >> nbElems >> d;
		
		vector<int> elems;
		for(int iElem = 0;iElem < nbElems;iElem++) {
			int elem;
			cin >> elem;
			elems.push_back(elem);
		}	
		
		sort(elems.begin(), elems.end());
		
		if(elems[0] + elems[1] > d && elems.back() > d) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
	return 0;
}