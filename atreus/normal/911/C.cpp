#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <cmath>

#define MP make_pair
#define F first
#define S second
#define PB push_back

using namespace std;

const int maxn = 1e5 + 100;
int a[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n = 3;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort (a, a + n);
	if (a[0] == 1)
		return cout << "YES" << endl, 0;
	if (a[0] == 2 and a[1] == 2)
		return cout << "YES" << endl, 0;
	if (a[0] == 2 and a[1] == 4 and a[2] == 4)
		return cout << "YES" << endl, 0;
	if (a[1] == 3 and a[2] == 3 and a[0] == 3)
		return cout << "YES" << endl, 0;
	cout << "NO" << endl;
}