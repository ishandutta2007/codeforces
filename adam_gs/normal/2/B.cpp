#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=1e3+7;
int a[LIM][LIM], b[LIM][LIM], dpa[LIM][LIM],dpb[LIM][LIM];
int pot2[LIM], pot5[LIM];
char ans[3*LIM];
int f2(int x) {
	int p=0, k=29;
	while(p<k) {
		int sr=(p+k+1)/2;
		if(x%pot2[sr]==0) p=sr; else k=sr-1;
	}
	return p;
}
int f5(int x) {
	int p=0, k=12;
	while(p<k) {
		int sr=(p+k+1)/2;
		if(x%pot5[sr]==0) p=sr; else k=sr-1;
	}
	return p;
}
void wypisz(int n, int a, int b) {
	cout << "1\n";
	int i=1, j=1;
	while(i<a) {
		cout << 'D';
		++i;
	}
	while(j<n) {
		cout << 'R';
		++j;
	}
	while(i<n) {
		cout << 'D';
		++i;
	}
	cout << '\n';
}
void solve() {
	int zx=-1, zy=-1;
	pot2[0]=pot5[0]=1;
	rep(i, 29) {
		pot2[i+1]=pot2[i]*2;
	}
	rep(i, 12) pot5[i+1]=pot5[i]*5;
	int n;
	cin >> n;
	rep(i, n) rep(j, n) {
		int x;
		cin >> x;
		if(x==0) {
			zx=i+1;
			zy=j+1;
		}
		a[i+1][j+1]=f2(x);
		b[i+1][j+1]=f5(x);
	}
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) {
		if(i==1) {
			dpa[i][j]=dpa[i][j-1]+a[i][j];
			dpb[i][j]=dpb[i][j-1]+b[i][j];
		} else if(j==1) {
			dpa[i][j]=dpa[i-1][j]+a[i][j];
			dpb[i][j]=dpb[i-1][j]+b[i][j];
		} else {
			dpa[i][j]=min(dpa[i-1][j], dpa[i][j-1])+a[i][j];
			dpb[i][j]=min(dpb[i-1][j], dpb[i][j-1])+b[i][j];
		}
	}
	if(min(dpa[n][n], dpb[n][n]) && zx!=-1) {
		wypisz(n, zx, zy);
		return;
	}
	cout << min(dpa[n][n], dpb[n][n]) << '\n';
	int x=n, y=n;
	if(dpa[n][n]<=dpb[n][n]) {
		rep(i, 2*(n-1)) {
			if(x==1) {
				ans[i]='R';
				--y;
			} else if(y==1) {
				ans[i]='D';
				--x;
			} else {
				if(dpa[x-1][y]<dpa[x][y-1]) {
					ans[i]='D';
					--x;
				} else {
					ans[i]='R';
					--y;
				}
			}
		}
	} else {
		rep(i, 2*(n-1)) {
			if(x==1) {
				ans[i]='R';
				--y;
			} else if(y==1) {
				ans[i]='D';
				--x;
			} else {
				if(dpb[x-1][y]<dpb[x][y-1]) {
					ans[i]='D';
					--x;
				} else {
					ans[i]='R';
					--y;
				}
			}
		}
	}
	for(int i=2*(n-1)-1; i>=0; --i) cout << ans[i];
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}