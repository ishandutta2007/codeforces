#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
const double PI = 3.1415926535897932384626433;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, r;
	cin >> N >> r;
	double R = r / ((1.0 / sin(PI / N)) - 1);
	cout << fixed << setprecision(15) << R << endl;
}