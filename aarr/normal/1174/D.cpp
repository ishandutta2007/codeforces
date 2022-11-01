#include <iostream>
#include <vector>
using namespace std;

int mark[300000];
vector <int> v;
int main() {
	ios :: sync_with_stdio(false);
	int n, x;
	cin >> n;
	cin >> x;
	v.push_back(0);
	mark[x] = 1;
	mark[0] = 1;
	for (int i = 1 ; i < (1 << n); i++) {
		if (mark[i] == 0) {
			v.push_back(i);
			mark[i] = 1;
			mark[i ^ x] = 1;
		}
	}
	cout << v.size() - 1 << endl;
	for (int i = 1; i < v.size(); i++) {
		cout << (v[i] ^ v[i - 1]) << " ";
	}
	return 0;
}