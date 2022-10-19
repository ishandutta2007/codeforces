#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M 111

bool make(int *a, int n){

	if (n == 2){
		a[0] = 3;
		a[1] = 4;
		return 1;
	}
	
	for (int x = 1; x <= 1000; ++x)
	for (int y = 1; y <= x; ++y){
		int v = 4 * (n-1) - (x*x - y*y);
		if (v >= 0 && v % 3 == 0 && v / 3 <= n - 1){
			a[0] = y;
			v /= 3;
			for (int i = 1; i <= v; ++i)
				a[i] = 1;
			for (int i = v + 1; i < n; ++i)
				a[i] = 2;
			return 1;
		}
	}

	return 0;
}

int sum(int *a, int n){
	int s = 0;
	for (int i = 0; i < n; ++i)
		s = s + a[i] * a[i];
	return s;
}

int a[M], b[M];

int main(){
#ifdef GORILLA
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
#endif

	int n, m;
	cin >> n >> m;
	
	make(a, n);
	make(b, m);
	for (int i = 0; i < n; ++i,cout<<"\n")
	for (int j = 0; j < m; ++j,cout<<" ")
		cout << a[i] * b[j];

	return 0;
}