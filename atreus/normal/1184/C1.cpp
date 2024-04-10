#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 5e5 + 3;
const int mod = 1e6 + 7;

int x[50], y[50], a[60], b[60];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < 4 * n + 1; i++){
		cin >> x[i] >> y[i];
		a[x[i]] ++;
		b[y[i]] ++;
	}
	int minx = 50, maxx = 0;
	int miny = 50, maxy = 0;
	for (int i = 0; i <= 50; i++){
		if (a[i] >= n){
			minx = min(minx, i);
			maxx = max(maxx, i);
		}
		if (b[i] >= n){
			miny = min(miny, i);
			maxy = max(maxy, i);
		}
	}
	for (int i = 0; i < 4 * n + 1; i++){
		if (x[i] > maxx or x[i] < minx or y[i] > maxy or y[i] < miny)
			return cout << x[i] << " " << y[i] << endl, 0;
		if ((x[i] < maxx and x[i] > minx) and (y[i] < maxy and y[i] > miny))
			return cout << x[i] << " " << y[i] << endl, 0;
	}
}