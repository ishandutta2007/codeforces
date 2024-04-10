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
const int maxn = 1e5 + 5;
int c[maxn], a[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	bool cur = 1;
	for (int i = 0; cur and i < s.size(); i++) {
		if (s[i] == '0')
			cout << s[i];
		if (s[i] == '2')
			cur = 0;
	}
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '1')
			cout << s[i];
	cur = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '2')
			cur = 0;
		if (!cur and s[i] != '1')
			cout << s[i];
	}
	cout << endl;
}