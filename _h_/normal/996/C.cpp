#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

void fail(){
	cout << -1 << endl;
	exit(0);
}

int dx[4] = {0,-1,0,1}, dy[4] = {1,0,-1,0};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<vi> r(4, vi(n));

	trav(v, r) trav(x, v) cin >> x;

	vi ians, rans, cans;

	auto move = [&](int x, int y, int t){
		assert(x==1 || x==2);
		assert(y >= 0);
		assert(y < n);

		if(r[x][y] == 0){
			return;
		}

		ians.push_back(r[x][y]);
		int xx = x+dx[t], yy = y+dy[t];

		if(xx==0 || xx==3) assert(r[x][y] == r[xx][yy]);
		else assert(r[xx][yy] == 0);
		assert(yy >= 0);
		assert(yy < n);

		rans.push_back(xx);
		cans.push_back(yy);
		
		r[xx][yy] = r[x][y];
		r[x][y] = 0;

	};

	rep(i,0,n){
		if(r[0][i] == r[1][i])
			move(1, i, 1);
		if(r[3][i] == r[2][i])
			move(2, i, 3);
	}

	if(k == 2*n && ians.empty()) fail();

	start:

	rep(i,1,3) rep(j,0,n) if(r[i][j]){
		
		int xd, yd;
		for(int xx = 0; xx <= 3; xx += 3){
			rep(yy,0,n){
				if(r[xx][yy] == r[i][j])
					xd = xx, yd = yy;
			}
		}
		
		
		if( abs(xd-i)>1 ){
			rep(xx,1,3) rep(yy,0,n){
				if(r[xx][yy]==0){
					if(abs(xd-xx)>1){
						move(3-xx,yy, xx==1 ? 1 : 3);
						xx = 3-xx;
					}
					while(yy != j){
						if(yy > j){
							move(xx, yy-1, 0);
							yy--;
						}
						else {
							move(xx, yy+1, 2);
							yy++;
						}
					}
					move(i, j, i==1 ? 3 : 1);
					i = 3-i;
					goto close;
				}
			}
		}
		close:

		if(j == yd){
			move(i, j, i==1 ? 1 : 3);
			goto start;
		}

		int xe, ye;
		rep(xx,1,3) rep(yy,0,n) if(r[xx][yy]==0){
			xe = xx;
			ye = yy;
		}
		

		if(ye == j){
			if(ye > 0){
				move(xe, ye-1, 0);
				--ye;
			} else {
				move(xe, ye+1, 2);
				++ye;
			}
		}

		if(xe != i){
			move(3-xe, ye, xe==1 ? 1:3);
			xe = 3-xe;
		}

		while(abs(ye-j) > 1){
			if(ye > j){
				move(xe, ye-1, 0);
				--ye;
			} else {
				move(xe, ye+1, 2);
				++ye;
			}
		}


		if(abs(yd-j) > abs(ye-yd)){
			move(i,j, j>yd ? 2 : 0);
			swap(j, ye);
		}
		while(yd != j){
			if(yd < j){
				move(3-i, ye, i==1 ? 1 : 3);
				move(3-i, ye-1, 0);
				move(3-i, ye-2, 0);
				move(i, j-1, i==1 ? 3 : 1);
				move(i, j, 2);
				--j, --ye;
			} else {
				move(3-i, ye, i==1 ? 1 : 3);
				move(3-i, ye+1, 2);
				move(3-i, ye+2, 2);
				move(i, j+1, i==1 ? 3 : 1);
				move(i, j, 0);
				++j, ++ye;
			}
		}
		move(i,j, i==1 ? 1 : 3);
		goto start;
	}

	int m = sz(ians);
	cout << m << endl;
	rep(i,0,m) cout << ians[i] << ' ' << rans[i]+1 << ' ' << cans[i]+1 << endl;
}