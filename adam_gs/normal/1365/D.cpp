#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pr(a, b) make_pair(a, b)
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		bool bl=true;
		int n, m;
		cin >> n >> m;
		string T[n];
		rep(i, n) cin >> T[i];
		int li=0;
		rep(i, n) rep(j, m) if(T[i][j]=='G') ++li;
		if(T[n-1][m-1]=='B' || T[n-1][m-1]=='#') bl=false;
		rep(i, n) rep(j, m) {
			if(T[i][j]!='B') continue;
			if((i>0 && T[i-1][j]=='G') || (j>0 && T[i][j-1]=='G') || (i<n-1 && T[i+1][j]=='G') || (j<m-1 && T[i][j+1]=='G')) bl=false;
			if(i>0 && T[i-1][j]!='B') T[i-1][j]='#';
			if(j>0 && T[i][j-1]!='B') T[i][j-1]='#';
			if(i<n-1 && T[i+1][j]!='B') T[i+1][j]='#';
			if(j<m-1 && T[i][j+1]!='B') T[i][j+1]='#';
		}
		if(T[n-1][m-1]=='#') bl=false;
		if(bl) {
		int odw[n][m];
		rep(i, n) rep(j, m) odw[i][j]=0;
		queue<pair<int,int> >q;
		q.push(pr(n-1, m-1));
		odw[n-1][m-1]=1;
		while(!q.empty()) {
			int x=q.front().first, y=q.front().second; q.pop();
			if(x>0 && (T[x-1][y]=='.' || T[x-1][y]=='G') && odw[x-1][y]==0) {
				odw[x-1][y]=1;
				q.push(pr(x-1, y));
			}
			if(y>0 && (T[x][y-1]=='.' || T[x][y-1]=='G') && odw[x][y-1]==0) {
				odw[x][y-1]=1;
				q.push(pr(x, y-1));
			}
			if(x<n-1 && (T[x+1][y]=='.' || T[x+1][y]=='G') && odw[x+1][y]==0) {
				odw[x+1][y]=1;
				q.push(pr(x+1, y));
			}
			if(y<m-1 && (T[x][y+1]=='.' || T[x][y+1]=='G') && odw[x][y+1]==0) {
				odw[x][y+1]=1;
				q.push(pr(x, y+1));
			}
		}
		rep(i, n) rep(j, m) if(T[i][j]=='G' && odw[i][j]==0) bl=false;
		}
		if(li==0 && T[n-1][m-1]!='B') bl=true;
		if(bl) cout << "Yes\n"; else cout << "No\n";
	}
}