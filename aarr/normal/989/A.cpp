#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];
vector <int> vec;
deque <int> q;
bool mark[N];
int d[55][55];

int main() {
	string s;
	cin >> s;
	for (int i = 1; i + 1 < s.size(); i++) {
		if (s[i] != s[i - 1] && s[i] != s[i + 1] && s[i + 1] != s[i - 1] && s[i] != '.' && s[i - 1] != '.' && s[i + 1] != '.') {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}