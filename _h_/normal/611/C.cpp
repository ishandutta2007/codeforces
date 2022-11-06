#include <iostream>
#include <vector>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
typedef vector<int> vi;

int main(){
	cin.sync_with_stdio(0);
	int h,w;
	cin >> h >> w;
	vector<string> grid(h);
	for(string &s : grid)
		cin >> s;
	vector<vi> hor(h+1,vi(w)), ver(h+1,vi(w));
	rep(i,0,h) rep(j,0,w){
		hor[i+1][j] = hor[i][j] + (j+1<w && grid[i][j]=='.'&&grid[i][j+1]=='.');
		ver[i+1][j] = ver[i][j] + (i+1<h && grid[i][j]=='.'&&grid[i+1][j]=='.');
	}
	int q;
	cin >> q;
	while(q--){
		int r1,c1,r2,c2,ans=0;
		cin>>r1>>c1>>r2>>c2;
		--r1,--r2,--c1,--c2;
		rep(c,c1,c2+1){
			if(c!=c2)
				ans+=hor[r2+1][c]-hor[r1][c];
			ans+=ver[r2][c]-ver[r1][c];
		}
		cout << ans << endl;
	}
}