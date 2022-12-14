#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <set>
#include <unordered_map>
#include <cmath>
#include <unordered_set>
#include <map>
#include <queue>

#define MP make_pair
#define F first
#define S second
#define PB push_back

using namespace std;

const int maxn = 1e3 + 100;
pair <int, int> a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a[i].F;
		a[i].S = i + 1;
	}
	sort (a, a + n);
	int l = 0;
	vector <int> v;
	for (int i = 0; i < n; i++){
		l += a[i].F;
		if (l <= k)
			v.push_back(a[i].S);
	}
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}