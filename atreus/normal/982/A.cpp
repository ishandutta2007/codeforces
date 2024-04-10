#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
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
typedef long double ld;
const int mod = (int)1e9 + 7;
const int maxn = 1e5 + 100;;
const int inf = (int)1e9;

int main(){
	ios::sync_with_stdio(false);
	string s;
	int n;
	cin >> n >> s;
	bool cur = 1;
	if (n == 1 and s == "0")
		return cout << "No" << endl, 0;
	if (n == 2 and s == "00")
		return cout << "No" << endl, 0;
	for (int i = 0; i < s.size() - 1; i++)
		if (s[i] == '1' and s[i + 1] == '1')
			cur = 0;
	for (int i = 1; i < s.size() - 1; i++)
		if (s[i - 1] == '0' and s[i] == '0' and s[i + 1] == '0')
			cur = 0;
	if (s[0] == '0' and s[1] == '0')
		cur = 0;
	if (s[n - 1] == '0' and s[n - 2] == '0')
		cur = 0;
	if (cur)
		return cout << "Yes" << endl, 0;
	cout << "No" << endl;
}