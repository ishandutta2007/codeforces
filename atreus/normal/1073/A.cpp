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
bool mark[30];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < s.size(); i++)
		mark[s[i] - 'a'] = 1;
	int cnt = 0;
	for (int i = 0; i < 26; i++)
		cnt += mark[i];
	if (cnt == 1)
		return cout << "NO" << endl, 0;
	cout << "YES" << endl;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] != s[i + 1]) {
			cout << s[i] << s[i + 1] << endl;
			return 0;
		}
	}
}