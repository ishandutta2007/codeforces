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
const int maxn = 2e5 + 5;
const int maxm = 2e3 + 100;
const int mod = 1e9 + 7;
const ll inf = (1ll << 62);
const int block = 317;

bool mark[maxn];

int main () {
	ios_base::sync_with_stdio (false);
	int n, k;
	string s;
	cin >> n >> k >> s;
	s = " " + s;
	int tmp = 0;
	for (int i = 1; i <= k; i++) {
		if (s[i] == '(')
			tmp ++;
		else
			tmp --;
	}
	if (tmp == 0)
		return cout << s.substr (1, k) << endl, 0;
	
	stack <int> st;
	for (int i = 1; i <= k; i++) {
		if (s[i] == '(') {
			st.push (i);
		}
		else {
			st.pop();
		}
	}
	for (int i = k + 1; i <= n; i++) {
		if (s[i] == '(') {
			mark[i] = 1;
		}
		else {
			int u = st.top();
			mark[u] = 1;
			st.pop();
			st.pop();
			if (st.empty()) {
				for (int j = i + 1; j <= n; j++)
					mark[j] = 1;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (!mark[i])
			cout << s[i];
	cout << endl;
}