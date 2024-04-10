#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll s = 0, b = 0, w = 0;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		s += x;
		b += (x >> 1);
		w += (x >> 1);
		if (x & 1){
			if (i & 1)
				b ++;
			else
				w ++;
		}
	}
	cout << (s - abs(b - w)) / 2 << endl;
}