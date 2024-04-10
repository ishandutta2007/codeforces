/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define mp make_pair

using namespace std;

int main() {
	vector <int> ans;

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;

		cin >> x;

		ans.push_back(x);
	}

	sort(ans.begin(), ans.end());

	cout << ans[n / 2] << endl;

	return 0;
}