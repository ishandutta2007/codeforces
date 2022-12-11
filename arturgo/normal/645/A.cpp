#include <iostream>
#include <algorithm>
using namespace std;

string chaines[2];

int main() {
	for(int iFois = 0;iFois < 2;iFois++) {
		char a, b, c, d;
		cin >> a >> b >> c >> d;
		
		if(a != 'X')
			chaines[iFois] += a;
		if(b != 'X')
			chaines[iFois] += b;
		if(d != 'X')
			chaines[iFois] += d;
		if(c != 'X')
			chaines[iFois] += c;
	}
	
	for(int i = 0;i < 3;i++) {
		if(chaines[0] == chaines[1]) {
			cout << "YES" << endl;
			return 0;
		}
		rotate(chaines[0].begin(), chaines[0].begin() + 1, chaines[0].end());
	}
	
	cout << "NO" << endl;
	return 0;
}