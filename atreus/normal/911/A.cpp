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
vector <int> v;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int minn = 1000 * 1000 * 1000;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		minn = min(minn, a[i]);
	}
	for (int i = 0; i < n; i++){
		if (a[i] == minn)
			v.push_back(i);
	}
	minn = 1000 * 1000 * 1000;
	for (int i = 1; i < v.size(); i++){
		minn = min (minn, v[i] - v[i - 1]);
	}
	cout << minn << endl;
}