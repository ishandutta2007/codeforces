#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int maxn = 1e3 + 100;
vector <char> al;
int dp[maxn], a[maxn];
vector <int> vl, ix;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int k, a, b, v;
	cin >> k >> a >> b >> v;
	int needsection = (a + v - 1) / v;
	for (int i = 1; i <= 1000; i++){
		int m = i;
		m += min (b, i * (k - 1));
		if (m >= needsection)
			return cout << i << endl, 0;
	}
}