# include <bits/stdc++.h>

using namespace std;

const int xn = 5e5+10;
int a[xn];

int main(){
	//cout << (-8)%3;
	long long int n, l, r;
	cin >> n;
	long long s = 0;
	for (int i=0; i<n; i++) cin >> a[i], s += a[i];
	long long k = s/3;
	if (s%3 != 0){
		cout << 0;
		return 0;
	}
	if (s == 0){
		int t = 0;
		s = 0;
		for (int i=0; i<n; i++){
			s += a[i];
			if (s == 0) t += 1;
		}
		n = t;
		cout << ((n-1)*(n-2))/2;
		return 0;
	}
	l = 0, r = 0, s = 0;
	long long ans = 0;
	for (int i=0; i<n-1; i++){
		s += a[i];
		if (s == k and i < n-2) l += 1;
		else if (s == 2*k) r += 1, ans += l;
	}
	cout << ans;
}