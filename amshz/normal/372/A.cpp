# include <bits/stdc++.h>

using namespace std;

const int xn = 5e5;
int a[xn];

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a,a+n);
	int l = 0;
	int r = n/2;
	int t = 0;
	int last = r;
	while (l < last and r < n){
		if (a[r] >= a[l]*2)
			l += 1, r += 1, t += 1;
		else
			r += 1;
	}
	cout << n-t;
	return 0;
}