#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
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

const long long inf = 1e9;
const int maxn = 3e5 + 100;
int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	bool inc = 0, con = 0, dec = 0;
	for (int i = 1; i < n; i++){
		if (inc == 1 and a[i] > a[i - 1])
			return cout << "NO" << endl, 0;
		if (con == 1 and a[i] == a[i - 1])
			return cout << "NO" << endl, 0;
		if (a[i] <= a[i - 1])
			inc = 1;
		if (a[i] < a[i - 1])
			con = 1;
	}
	cout << "YES" << endl;
}