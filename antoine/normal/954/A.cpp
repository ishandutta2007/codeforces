#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <stack>
#include <memory>

using namespace std;

void f(string &s, string sub) {
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	string s;
	cin >> n >> s;

	for(;;) {
		int i = s.find("UR");
		int j  = s.find("RU");
		if (i == -1 && j == -1)
			break;
		i = i == -1 ? j : j == -1 ? i : min(i, j);
		s = s.replace(i, 2, "D");
	}
	cout << s.size();
	return 0;
}