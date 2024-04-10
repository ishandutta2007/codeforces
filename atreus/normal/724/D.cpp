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

int a[30];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	
	int last = -1, m = 0, M = 26;
	for (int i = 0; i < s.size(); i++) {
		M = min (M, int (s[i] - 'a'));
		if (int (s[i] - 'a') <= m) {
			last = i;
			M = 26;
		}

		if (i - last == n) {
			m = M;
			i -= n;
		}
	}
	
	last = -1, M = -1;
	for (int i = 0; i < s.size(); i++) {
		if (int (s[i] - 'a') < m) {
			a[int (s[i] - 'a')] ++;
			last = i;
		}
		else if (int (s[i] - 'a') == m)
			M = i;
		
		if (i - last == n) {
			last = M;
			a[m] ++;
		}
	}
	for (int i = 0; i < 26; i++)
		for (int j = 1; j <= a[i]; j++)
			cout << char (i + 'a');
	cout << endl;
}