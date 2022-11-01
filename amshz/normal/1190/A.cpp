# include <bits/stdc++.h>

using namespace std;

const long long int xn = 1e5;
long long int a[xn];

int main(){
	long long n ,m ,k;
	cin >> n >> m >> k;
	for (int i=0; i<m; i++)
		cin >> a[i];
	long long int l = 0;
	long long int last = 0;
	long long  r;
	long long int ans = 0;
	long long int cam = 0;
	while (l < m){
		last = l;
		r = (a[l]-cam-1)/k+1;
		while ((a[l]-cam-1)/k+1 <= r)
			l += 1;
		ans += 1, cam += l-last;
	}
	cout << ans;
}