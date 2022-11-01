#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;


const int D = 86400;
bool b[105];


int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	int n;
	cin >> n;
	for (int i = 20; i > 0; i--) {
		if (get(n, i - 1)) {
			cout << i << " ";
		}
	}
}