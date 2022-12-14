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
const int maxn = 2e5 + 37;
bool mark[maxn];
int a[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	stack <int> s;
	for (int i = n - 1; i >= 0; i--)
		s.push (a[i]);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (mark[x]) {
			cout << 0 << " ";
			continue;
		}
		else {
			int cnt = 1;
			while (s.top() != x) {
				mark[s.top()] = 1;
				s.pop();
				cnt ++;
			}
			cout << cnt << " ";
			mark[x] = 1;
			s.pop();
		}
	}
	cout << endl;
}