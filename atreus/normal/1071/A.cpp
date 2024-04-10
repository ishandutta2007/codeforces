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
const int maxn = 1e5 + 37;
int mark[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	int i = 1, cnt = 0;
	while (a >= i) {
		mark[i] = 1;
		a -= i;
		i ++;
		cnt ++;
	}
	
	int cnt2 = 0;
	if (a > 0 and b >= i - a) {
		mark[i - a] = 2;
		mark[i] = 1;
		b -= (i - a);
		cnt2 ++;
		a = 0;
		i ++;
	}

	while (b >= i) {
		b -= i;
		mark[i] = 2;
		i ++;
		cnt2 ++;
	}
	cout << cnt << endl;
	for (int i = 1; i <= 100000; i++)
		if (mark[i] == 1)
			cout << i << " ";
	cout << endl;
	cout << cnt2 << endl;
	for (int i = 1; i <= 100000; i++)
		if (mark[i] == 2)
			cout << i << " ";
	cout << endl;
}