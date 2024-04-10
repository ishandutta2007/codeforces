#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int nb;
	cin >> nb;
	
	int t1 = 0, t2 = 0;
	
	vector<int> lol;
	for(int i = 0;i < nb;i++) {
		int v;
		cin >> v;
		t2 += v;
		lol.push_back(v);
	}
	
	int x, y;
	cin >> x >> y;
	
	for(int i = 0;i < nb;i++) {
		if(x <= t1 && x <= t2 && t1 <= y && t2 <= y) {
			cout << i + 1 << endl;
			return 0;
		} 
		
		t1 += lol[i];
		t2 -= lol[i];
	}
	
	cout << 0 << endl;
	return 0;
}