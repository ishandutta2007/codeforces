#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int add (string s) {
	string k = s.substr (0, 2);
	if (k == "mo")
		return 2;
	if (k == "tu")
		return 3;
	if (k == "we")
		return 4;
	if (k == "th")
		return 5;
	if (k == "fr")
		return 6;
	if (k == "sa")
		return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	string fi, se;
	cin >> fi >> se;
	int a = add (fi), b = add (se);
	if ((a + 31) % 7 == b or (a + 30) % 7 == b or (a + 28) % 7 == b)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}