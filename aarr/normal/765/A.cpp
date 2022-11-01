#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;


const int N = 55;
int a[N][N];


int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		string ashghal;
		cin >> ashghal;
	}
	if (n % 2) {
		cout << "contest";
	}
	else {
		cout << "home";
	}
}