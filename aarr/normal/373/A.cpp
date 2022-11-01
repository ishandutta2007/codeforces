#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];
int b[N];
vector <char> vec;
deque <int> q;
bool mark[N];
char c[55][55];

int main() {
	int k;
	cin >> k;
	for (int i = 0; i < 4; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 4; j++) {
			if (s[j] != '.') {
				a[s[j] - '0']++;
			}
		}
	}
	for (int i = 1; i < 10; i++) {
		if (a[i] > k * 2) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}