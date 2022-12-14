#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define F first
#define S second
using namespace std;

const int maxn = 2e5 + 100;
pair <pair <int, int>, int> a[maxn];

int main (){
	int n, t;
	cin >> n >> t;
	for (int i = 0; i < n; i++){
		cin >> a[i].F.S >> a[i].F.F;
		a[i].S = i + 1;
	}
	sort (a, a + n);
	int l = 0, r = n + 1;
	while (r - l > 1){
		int mid = (r + l) / 2;
		int p = 0;
		int T = 0;
		for (int j = 0; j < n; j++){
			if (T + a[j].F.F <= t and a[j].F.S >= mid){
				p ++;
				T += a[j].F.F;
			}
		}
		if (p >= mid)
			l = mid;
		else
			r = mid;
	}
	cout << l << endl;
	cout << l << endl;
	int p = 0;
	int T = 0;
	int mid = l;
	for (int j = 0; j < n; j++){
		if (T + a[j].F.F <= t and a[j].F.S >= mid){
			p ++;
			T += a[j].F.F;
			cout << a[j].S << " ";
			if (p == l)
				return 0;
		}
	}
}