#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cmath>
#include <unordered_set>
#include <map>
#include <deque>
#include <unordered_map>
#include <fstream>
#include <set>
#include <algorithm>
#include <iomanip>
#define fin cin
#define fout cout
#define F first
#define S second
#define PB push_back
#define PF push_front
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn = 500 + 5;
const int maxm = 2e3 + 100;
const int mod = 1e9 + 7;
const ll inf = (1ll << 62);
const int block = 317;

bool mark[maxn][maxn];

int main () {
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	int x = 1, y = 1;
	for (int i = 1; i <= n - 1; i++) {
		mark[x][y] = 1;
		cout << "? " << x + 1 << " " << y << " " << n << " " << n << endl;
		string k;
		cin >> k;
		if (k == "YES") {
			x ++;
		}
		else {
			y ++;
		}
		mark[x][y] = 1;
	}
	x = n, y = n;
	for (int i = 1; i <= n - 1; i++) {
		cout << "? " << 1 << " " << 1 << " " << x << " " << y - 1 << endl;
		mark[x][y] = 1;
		string k;
		cin >> k;
		if (k == "YES") {
			y --;
		}
		else {
			x --;
		}
		mark[x][y] = 1;
	}
	x = 1, y = 1;
	cout << "! ";
	for (int i = 1; i <= 2 * n - 2; i++) {
		if (mark[x + 1][y]) {
			cout << 'D';
			x ++;
		}
		else {
			cout << 'R';
			y ++;
		}
	}
	cout << endl;

}