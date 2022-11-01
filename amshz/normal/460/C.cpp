# include <bits/stdc++.h>

using namespace std;

const int xn = 1e5+10;
long long a[xn], n, m, w;

bool check(long long x){
	long long now = 0;
	long long remained= m;
	long long b[xn];
	for (int i=0; i<n; i++) b[i] = 0;
	for (int i=0; i<n; i++){
		if (i >= w) now -= b[i-w];
		if (now+a[i] < x){
			remained -= x-now-a[i];
			b[i] = x-now-a[i];
			now += x-now-a[i];
		}
	}
	return remained >= 0;
}

int main(){
	cin >> n >> m >> w;
	for (int i=0; i<n; i++) cin >> a[i];
	long long l = 0, r = 1e12;
	while (l+1 < r){
		long long x = l+(r-l)/2;
		if (check(x)) l = x;
		else r = x;
	}
	cout << l;
	return 0;
}