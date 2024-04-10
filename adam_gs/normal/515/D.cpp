#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e3+7;
int dx[]={1, 0, -1, 0}, dy[]={0, 1, 0, -1};
queue<pair<pair<int,int>,int>>q;
string T[LIM], ans[LIM];
int ile[LIM][LIM], odw[LIM][LIM], n, m;
bool ok(int a, int b) {
	return 0<=a && a<n && 0<=b && b<m;
}
void wrzuc(int a, int b) {
	if(odw[a][b]) return;
	rep(i, 4) if(ok(a+dx[i], b+dy[i]) && T[a+dx[i]][b+dy[i]]=='.' && !odw[a+dx[i]][b+dy[i]]) {
		q.push({{a, b}, i});
		odw[a][b]=odw[a+dx[i]][b+dy[i]]=1;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	rep(i, n) {
		cin >> T[i];
		ans[i]=T[i];
	}
	rep(i, n)rep(j, m) if(T[i][j]=='.') {
		rep(l, 4) if(ok(i+dx[l], j+dy[l]) && T[i+dx[l]][j+dy[l]]=='.') ++ile[i][j];
	}
	rep(i, n) rep(j, m) if(ile[i][j]==1 && !odw[i][j]) wrzuc(i, j);
	while(!q.empty()) {
		int a=q.front().st.st, b=q.front().st.nd, p=q.front().nd; q.pop();
		if(p==0) {
			ans[a][b]='^';
			ans[a+1][b]='v';
		} else if(p==1) {
			ans[a][b]='<';
			ans[a][b+1]='>';
		} else if(p==2) {
			ans[a][b]='v';
			ans[a-1][b]='^';
		} else {
			ans[a][b]='>';
			ans[a][b-1]='<';
		}
		rep(i, 4) {
			if(ok(a+dx[i], b+dy[i])) {
				--ile[a+dx[i]][b+dy[i]];
				if(T[a+dx[i]][b+dy[i]]=='.' && ile[a+dx[i]][b+dy[i]]==1) {
					wrzuc(a+dx[i], b+dy[i]);
				}
			}
			if(ok(a+dx[p]+dx[i], b+dy[p]+dy[i])) {
				--ile[a+dx[p]+dx[i]][b+dy[p]+dy[i]];
				if(T[a+dx[p]+dx[i]][b+dy[p]+dy[i]]=='.' && ile[a+dx[p]+dx[i]][b+dy[p]+dy[i]]==1) {
					wrzuc(a+dx[p]+dx[i], b+dy[p]+dy[i]);
				}
			}
		}
	}
	rep(i, n) rep(j, m) if(ans[i][j]=='.') {
		cout << "Not unique\n";
		return 0;
	}
	rep(i, n) cout << ans[i] << '\n';
}