#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());

int main() {
	// freopen("arithmetic.in", "r", stdin);
	// freopen("arithmetic.out", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string vic1, vic2;
	cin >> vic1 >> vic2;	
	int n;
	cin >> n;

	cout << vic1 << " " << vic2 << endl;
	for (int i = 0; i < n; ++i) {
		string s, t;
		cin >> s >> t;
		if (vic1 == s) {
			vic1 = t;
		} else {
			vic2 = t;
		}
		cout << vic1 << " " << vic2 << endl;

	}
	
}