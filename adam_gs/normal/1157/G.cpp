#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=207;
int T[LIM][LIM], K[LIM][LIM], rzad[LIM], kol[LIM], n, m;
bool spr() {
	pair<int,int>lst={-1, -1};
	rep(i, n) rep(j, m) if(!K[i][j]) lst={i, j};
	rep(i, n) rep(j, m) {
		if(i<lst.st || i==lst.st && j<=lst.nd) {
			if(K[i][j]) return false;
		} else {
			if(!K[i][j]) return false;
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> T[i][j];
	rep(i, m+1) {
		rep(j, n) rzad[j]=0;
		rep(j, m) {
			if(j<i) kol[j]=T[0][j]; else kol[j]=T[0][j]^1;
		}
		rep(a, n) rep(b, m) K[a][b]=T[a][b]^kol[b];
		rep(j, n-1) if(!K[j+1][0]) {
			rzad[j+1]=1;
			rep(l, m) K[j+1][l]^=1;
		}
		if(spr()) {
			cout << "YES\n";
			rep(j, n) cout << rzad[j];
			cout << '\n';
			rep(j, m) cout << kol[j];
			cout << '\n';
			return 0;
		}
	}
	rep(i, n) rzad[i]=0;
	rep(i, m) kol[i]=0;
	rep(i, m) if(T[0][i]) kol[i]=1;
	rep(i, n) rep(j, m) K[i][j]=T[i][j]^kol[j];
	int ma=0;
	rep(i, n-1) {
		bool zero=false, jeden=false;
		rep(j, m) if(K[i+1][j]) jeden=true; else zero=true;
		if(jeden && zero) ma=i+1;
	}
	rep(i, n-1) {
		if(i+1<=ma) {
			if(K[i+1][0]) {
				rzad[i+1]=1;
				rep(j, m) K[i+1][j]^=1;
			}
		} else {
			if(!K[i+1][0]) {
				rzad[i+1]=1;
				rep(j, m) K[i+1][j]^=1;
			}
		}
	}
	if(spr()) {
		cout << "YES\n";
		rep(i, n) cout << rzad[i];
		cout << '\n';
		rep(i, m) cout << kol[i];
		cout << '\n';
	} else cout << "NO\n";
}