#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 100;
int a[maxn], b[maxn], c[maxn];

int main (){
	int x1, y1, x2, y2, n;
	cin >> x1 >> y1 >> x2 >> y2 >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> b[i] >> c[i];
		bool d1 = 0, d2 = 0;
		if (b[i] != 0 and (-1.0 * a[i] * x1 - c[i]) / b[i] >= y1)
			d1 = 1;
		if (b[i] == 0 and (-1.0 * c[i] / a[i]) >= x1)
			d1 = 1;
		if (b[i] != 0 and (-1.0 * a[i] * x2 - c[i]) / b[i] >= y2)
			d2 = 1;
		if (b[i] == 0 and (-1.0 * c[i] / a[i]) >= x2)
			d2 = 1;
		if (d1 != d2)
			cnt ++;
	}
	cout << cnt << endl;
}