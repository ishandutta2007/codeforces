#include <bits/stdc++.h>

using namespace std;

const int maxn = 12345;

int a[5];

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int a, b, c;
		cin >> a >> b >> c;
		int cnt = 0;
		if (a > 0)
			cnt ++, a --;
		if (b > 0)
			cnt ++, b --;
		if (c > 0)
			cnt ++, c --;
		if (a < b)
			swap(a, b);
		if (a < c)
			swap(a, c);
		if (b < c)
			swap(b, c);
		if (a > 0 and b > 0)
			cnt ++, a --, b --;
		if (a > 0 and c > 0)
			cnt ++, a --, c --;
		if (b > 0 and c > 0)
			cnt ++, b --, c --;
		if (a > 0 and b > 0 and c > 0)
			cnt ++, a --, b --, c --;
		cout << cnt << endl;
	}
}