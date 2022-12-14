#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <set>
#include <queue>
#define F first
#define S second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 100;
int a[maxn];
vector <int> v[maxn];

int main (){
	memset (a, 63, sizeof a);
	string ks, s;
	cin >> ks;
	s = ' ' + ks;
	int n = s.size() - 1;
	a[0] = -(1 << 30);
	for (int i = 1; i <= n; i++){
		if (s[i] == '1'){
			if (i == 1)
				return cout << -1 << endl, 0;
			int idx = lower_bound (a, a + n, 1) - a - 1;
			if (idx >= i or idx <= 0)
				return cout << -1 << endl, 0;
			a[idx] = 1;
			v[idx].PB(i);
		}
		else {
			int idx = upper_bound (a, a + n, 0) - a;
			a[idx] = 0;
			v[idx].PB(i);
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++){
		if (v[i].size() == 0)
			break;
		ans = i;
		if (a[i] == 1)
			return cout << -1 << endl, 0;
	}
	cout << ans << endl;
	for (int i = 1; i <= ans; i++){
		cout << v[i].size() << " ";
		for (int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
}