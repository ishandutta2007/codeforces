#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 550 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
int n;
string s;

void chng (int idx) {
	string k;
	for (int i = idx - 1; i >= 0; i--)
		k += s[i];
	for (int i = idx; i < n; i++)
		k += s[i];
	s = k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> s;
	for (int i = 1; i <= n; i++) 
		if (n % i == 0)
			chng (i);
	cout << s << endl;
}