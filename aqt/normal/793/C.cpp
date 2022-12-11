
// Problem : C. Mice problem
// Contest : Codeforces - Tinkoff Challenge - Elimination Round
// URL : https://codeforces.com/contest/793/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int x, y, x2, y2;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> x >> y >> x2 >> y2;
	long double mn = 0, mx = 1e13;
	for(int i = 1; i<=N; i++){
		int sx, sy, vx, vy;
		cin >> sx >> sy >> vx >> vy;
		if(vy == 0){
			if(sy >= y2 || sy <= y){
				cout << -1 << "\n";
				return 0;
			}
		}
		else{
			mn = max((long double) (min(1.0*(y-sy)/vy, 1.0*(y2-sy)/vy)), mn);
			mx = min((long double) (max(1.0*(y-sy)/vy, 1.0*(y2-sy)/vy)), mx);
		}
		if(vx == 0){
			if(sx >= x2 || sx <= x){
				cout << -1 << "\n";
				return 0;
			}
		}
		else{
			mn = max((long double) (min(1.0*(x-sx)/vx, 1.0*(x2-sx)/vx)), mn);
			mx = min((long double) (max(1.0*(x-sx)/vx, 1.0*(x2-sx)/vx)), mx);
		}
	}
	//cout << mn << " " << mx << "\n";
	if(mn >= mx){
		cout << -1 << "\n";
	}
	else{
		cout << setprecision(12) << mn << "\n";
	}
}