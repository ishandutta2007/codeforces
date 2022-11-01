#include<bits/stdc++.h>
using namespace std;
long long a[4];
inline int minn() {
	if (a[1] < a[2] && a[1] < a[3]) return 1;
	if (a[2] < a[3]) return 2;
	return 3;
}
inline int maxn() {
	if (a[1] > a[2] && a[1] > a[3]) return 1;
	if (a[2] > a[3]) return 2;
	return 3;
}
int nomove;
inline void write(long long x) {
	cout << x << endl;
	cin >> nomove;
	if (nomove <= 0) exit(0);
	a[nomove] += x;
}
int main() {
	cin >> a[1] >> a[2] >> a[3];
	puts("First");
	int a1 = minn(), a3 = maxn(), a2;
	if (a1 != 1 && a3 != 1) a2 = 1;
	if (a1 != 2 && a3 != 2) a2 = 2;
	if (a1 != 3 && a3 != 3) a2 = 3;
	write(1000000000);
	a1 = minn(), a3 = maxn(), a2;
	if (a1 != 1 && a3 != 1) a2 = 1;
	if (a1 != 2 && a3 != 2) a2 = 2;
	if (a1 != 3 && a3 != 3) a2 = 3;
	write(3ll*a[nomove] - a[1] - a[2] - a[3]);
	a1 = minn(), a3 = maxn(), a2;
	if (a1 != 1 && a3 != 1) a2 = 1;
	if (a1 != 2 && a3 != 2) a2 = 2;
	if (a1 != 3 && a3 != 3) a2 = 3;
	write(a[a3] - a[a2]);
}