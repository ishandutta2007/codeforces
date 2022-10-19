#include <iostream>
using namespace std;

bool a[1000][1000];


int main() {
	int n, m;
	int sx, sy;
	int ex, ey;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			char c;
			cin >> c;
			a[i][j] = (c!='*');
			if(c=='S'){
				sx = i;
				sy = j;
			}
			if(c=='T'){
				ex = i;
				ey = j;
			}
			//cin >> a[i][j];
		}
	}
	
	bool valid = false;
	for(int i=0; i<n; i++){
		bool possible = true;
		for(int j=min(sx, i); j<=max(sx, i); j++){
			if(!a[j][sy]) possible = false;
		}
		for(int j=min(ey, sy); j<=max(ey, sy); j++){
			if(!a[i][j]) possible = false;
		}
		for(int j=min(ex, i); j<=max(ex, i); j++){
			if(!a[j][ey]) possible = false;
		}
		if(possible) valid = true;
	}
	for(int i=0; i<m; i++){
		bool possible = true;
		for(int j=min(sy, i); j<=max(sy, i); j++){
			if(!a[sx][j]) possible = false;
		}
		for(int j=min(ex, sx); j<=max(ex, sx); j++){
			if(!a[j][i]) possible = false;
		}
		for(int j=min(ey, i); j<=max(ey, i); j++){
			if(!a[ex][j]) possible = false;
		}
		if(possible) valid = true;
	}
	if(valid) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}