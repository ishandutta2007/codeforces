#include <iostream>
#include <algorithm>

using namespace std;

#define M 500500

int n,a[M];

void read(void){
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a + n);

}

bool check(int m){
	for (int i = 0, k = n - m; i < m; ++i)
	if (2 * a[i]>a[k + i])
		return 0;
	return 1;
}

void bin(void){
	int l = 0, r = n / 2;
	while (l < r){
		int m = (l + r) / 2;
		if (check(m + 1))
			l = m + 1;
		else
			r = m;
	}
	cout << n - l << "\n";
}

int main(){
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	read();
	bin();
	return 0;
}