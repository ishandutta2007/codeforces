#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

map<pair<int,int>, bool> mp;
vector<int> vX[maxn], vY[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++){
		int x, y;
		cin >> x >> y;
		vX[x].push_back(y);
		vY[y].push_back(x);
		mp[{x,y}] = 1;
	}
	for (int i = 1; i <= max(n, m); i++){
		sort(vX[i].begin(), vX[i].end());
		sort(vY[i].begin(), vY[i].end());
	}
	int x1 = 1, y1 = 1, x2 = n, y2 = m;
	int x = 1, y = 1;
	char d = 'R';
	while (x1 <= x2 and y1 <= y2){
//		cout << x1 << " " << y1 << " " << x2 << " " << y2 << " now " << x << " " << y << " - " << d << endl;
		if (d == 'R'){
			int idx = lower_bound(vX[x].begin(), vX[x].end(), y) - vX[x].begin();
			if (idx >= vX[x].size() or vX[x][idx] > y2){
				x1 ++;
				x ++;
				y = y2;
				d = 'D';
				continue;
			}
			for (int i = x1; i <= x2; i++)
				for (int j = vX[x][idx]; j <= y2; j++)
					if (!mp.count({i,j}))
						return cout << "No\n", 0;
			y2 = vX[x][idx] - 1;
			x1 ++;
			x ++;
			y = y2;
			d = 'D';
			continue;
		}
		if (d == 'D'){
			int idx = lower_bound(vY[y].begin(), vY[y].end(), x) - vY[y].begin();
			if (idx >= vY[y].size() or vY[y][idx] > x2){
				y2 --;
				x = x2;
				y --;
				d = 'L';
				continue;
			}
			for (int i = vY[y][idx]; i <= x2; i++)
				for (int j = y1; j <= y2; j++)
					if (!mp.count({i,j}))
						return cout << "No\n", 0;
			x2 = vY[y][idx] - 1;
			y2 --;
			x = x2;
			y --;
			d = 'L';
			continue;
		}
		if (d == 'L'){
			int idx = upper_bound(vX[x].begin(), vX[x].end(), y) - vX[x].begin() - 1;
			if (idx == -1 or vX[x][idx] < y1){
				x2 --;
				x --;
				y = y1;
				d = 'U';
				continue;
			}
			for (int i = x1; i <= x2; i++)
				for (int j = y1; j <= vX[x][idx]; j++)
					if (!mp.count({i,j}))
						return cout << "No\n", 0;
			y1 = vX[x][idx] + 1;
			x2 --;
			x --;
			y = y1;
			d = 'U';
			continue;
		}
		if (d == 'U'){
			int idx = upper_bound(vY[y].begin(), vY[y].end(), x) - vY[y].begin() - 1;
			if (idx == -1 or vY[y][idx] < x1){
				y1 ++;
				x = x1;
				y ++;
				d = 'R';
				continue;
			}
			for (int i = x1; i <= vY[y][idx]; i++)
				for (int j = y1; j <= y2; j++)
					if (!mp.count({i,j}))
						return cout << "No\n", 0;
			x1 = vY[y][idx] + 1;
			y1 ++;
			x = x1;
			y ++;
			d = 'R';
			continue;
		}
	}
	cout << "Yes\n";
}