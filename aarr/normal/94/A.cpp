#include <iostream>
#include <iomanip>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];
map <string, int> mp;
int b[N];
vector <char> vec;
deque <int> q;
bool mark[N];
char c[55][55];
string s[10], t[10];

bool get(int l, int r) {
	for (int i = 0; i <= r - l; i++) {
		if (s[l + i] != s[r - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 10; j++) {
			char c;
			cin >> c;
			t[i] += c;
		}
	}
	for (int i = 0; i < 10; i++) {
		string s;
		cin >> s;
		mp[s] = i;
	}
	for (int i = 0; i < 8; i++) {
		cout << mp[t[i]];
	}
}