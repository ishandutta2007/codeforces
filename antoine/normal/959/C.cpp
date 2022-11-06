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


using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	if (n < 6) {
		cout << "-1\n";
	}
	else {
		cout << "1 2\n3 2\n4 2\n";
		for (int i = 5; i <= n; ++i)
			cout << i << " 1\n";
	}
	for (int i = 2; i <= n; ++i)
		cout << i << " 1\n";
	return 0;
}