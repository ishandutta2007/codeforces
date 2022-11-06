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

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int hh, mm;
	cin >> hh >> mm;

	double H, D, C, N;
	cin >> H >> D >> C >> N;

	double ans = ceil(H / N) * C;

	int diff = hh >= 20 ? 0 : mm == 0 ? (20 - hh) * 60 : (20 - (hh + 1)) * 60 + 60 - mm;
	
	C *= .8;
	H += D * diff;
	
	ans = min(ans, ceil(H / N) * C);
	cout << fixed << setprecision(10);
	cout << ans;
	return 0;
}