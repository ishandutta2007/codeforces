#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=507;
int dx[]={1, 0, -1, 0}, dy[]={0, 1, 0, -1};
string T[LIM];
int odw[LIM][LIM], n, m;
int ile(int a, int b) {
	int ans=0;
	rep(i, 4) {
		int x=a+dx[i], y=b+dy[i];
		if(0<=x && x<n && 0<=y && y<m) {
			if(T[x][y]=='.') ++ans;
		}
	}
	return ans;
}
void solve() {
	cin >> n >> m;
	rep(i, n) cin >> T[i];
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2; --r1; --c1; --r2; --c2;
	if(r1==r2 && c1==c2) {
		cout << (ile(r1, c1)?"YES":"NO") << '\n';
		return;
	}
	if(abs(r1-r2)+abs(c1-c2)==1) {
		if(T[r2][c2]=='X') {
			cout << "YES\n";
		} else {
			cout << (ile(r2, c2)?"YES":"NO") << '\n';
		}
		return;
	} 
	queue<pair<int,int>>q;
	q.push({r1, c1});
	odw[r1][c1]=1;
	while(!q.empty()) {
		int a=q.front().st, b=q.front().nd; q.pop();
		rep(i, 4) {
			int x=a+dx[i], y=b+dy[i];
			if(0<=x && x<n && 0<=y && y<m) {
				if((T[x][y]=='.' || x==r2&&y==c2) && !odw[x][y]) {
					q.push({x, y});
					odw[x][y]=1;
				}
			}
		}
	}
	if(!odw[r2][c2]) {
		cout << "NO\n";
		return;
	}
	if(T[r2][c2]=='X') {
		cout << "YES\n";
		return;
	}
	cout << (ile(r2, c2)>1?"YES":"NO") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}