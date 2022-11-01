# include <bits/stdc++.h>

using namespace std;

const int xn = 1e5+10;
int a[xn], ans[xn];

bool cmp(int a, int b){
	return a>b;
}

int main(){
	int t;
	cin >> t;
	for (int i=0; i<t; i++){
		int n, r;
		cin >> n >> r;
		for (int j=0; j<n; j++) cin >> a[j];
		sort(a, a+n, cmp);
		int t = 0;
		int cm = 0;
		for (int j=0; j<n; j++){
			if (a[j]-cm <= 0) break;
			if (j > 0 and a[j] == a[j-1]) continue;
			t++;
			cm += r;
		}
		ans[i] = t;
	}
	for (int i=0; i<t; i++) cout << ans[i] << endl;
}