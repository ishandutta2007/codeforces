# include <bits/stdc++.h>

using namespace std;

const int xn = 2e5+10;
int a[xn], b[xn];

int bmm(int a, int b){
	if (a < b) swap(a,b);
	if (b == 0) return a;
	return bmm(b,a%b);
}

int main(){
	int n;
	cin >> n;
	int mx = 0;
	for (int i=0; i<n; i++) cin >> a[i], mx = max(mx,a[i]);
	for (int i=0; i<n; i++) b[i] = mx-a[i];
	int bm = b[0];
	for (int i=1; i<n; i++) bm = bmm(bm,b[i]);
	long long ans = 0;
	for (int i=0; i<n; i++) ans += b[i]/bm;
	cout << ans << ' ' << bm << endl;
}