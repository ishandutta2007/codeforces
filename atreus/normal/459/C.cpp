#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>

#define F first
#define S second

using namespace std;

const int maxn = 1e3 + 300;
vector <int> v[maxn];
int d;

void mab(int x, int k){
	int l = x;
	while (x > 0){
		v[l].push_back((x % k) + 1);
		x /= k;
	}
	while (v[l].size() < d){
		v[l].push_back(1);
	}
	reverse(v[l].begin(), v[l].end());
	return;
}

int main (){
	int n, k;
	cin >> n >> k >> d;
	long long power = 1;
	for (int i = 1; i <= d; i++){
		power *= k;
		if (power >= n)
			break;
		if (i == d)
			return cout << -1, 0;
	}
	if (d == 1 && n == 1 && d == 1){
		return cout << 1 << endl, 0;
	}
	for (int i = 1; i <= d; i++)
		v[0].push_back(1);
	for (int i = 1; i < n; i++)
		mab(i, k);
	for (int i = 0; i < d; i++){
		for (int j = 0; j < n; j++)
			cout << v[j][i] << " ";
		cout << endl;
	}
}