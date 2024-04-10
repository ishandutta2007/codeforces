#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 25 + 10;

ll a[maxn][maxn], lo[maxn][maxn], hi[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (i == 1)
				lo[i][j] = hi[i][j] = a[i][j] = 0;
			else{
				ll mxm = hi[i-1][j+1];
				if (j == n)
					mxm = -1;
				a[i][j] = mxm-lo[i-1][j]+1;
				mxm = hi[i-1][j]+a[i][j];
				if (j > 1)
					mxm = hi[i][j-1]+a[i][j];
				lo[i][j] = lo[i-1][j] + a[i][j];
				hi[i][j] = mxm;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	int q;
	cin >> q;
	while (q --){
		ll p;
		cin >> p;
		vector<pair<int,int>> loc;
		int x = n, y = n;
		while (x+y != 2){
			loc.push_back({x,y});
			if (x == 1){
				y --;
				continue;
			}
			if (y == 1){
				x --;
				continue;
			}
			p -= a[x][y];
			if (lo[x-1][y] <= p and p <= hi[x-1][y])
				x --;
			else
				y --;
		}
		loc.push_back({1,1});
		reverse(loc.begin(),loc.end());
		for (auto it : loc)
			cout << it.first << " " << it.second << endl;
	}
}