#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <iomanip>

#define PB push_back
#define MP make_pair
#define F first
#define S second

using namespace std;

const int maxn = 1e5 + 100;
int a[maxn];

int main (){
	long long A, B, x, y, z;
	cin >> A >> B >> x >> y >> z;
	long long ans = 0;
	long long k = 2 * x + y;
	long long l = 3 * z + y;
	if (k > A)
		ans += k - A;
	if (l > B)
		ans += l - B;
	cout << ans << endl;
}