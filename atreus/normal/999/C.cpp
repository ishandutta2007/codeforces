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
int n, a[30];
string s;

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	string s;
	cin >> n >> k >> s;
	for (int i = 0; i < n; i++)
		a[s[i] - 'a'] ++;
	int tmp = 0;
	for (int i = 0; i <= 26; i++) {
		tmp = i;
		if (k >= a[i])
			k -= a[i];
		else
			break;
	}
	for (int i = 0; i < n; i++) {
		if ((s[i] - 'a') < tmp)
			continue;
		if ((s[i] - 'a') == tmp and k > 0) {
			k --;
			continue;
		}
		cout << s[i];
	}
	cout << endl;
}