#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 100 + 5;
const int maxm = 10000 + 10;
const int mod = 1e9 + 7;

string s[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int x = 0, y = 0;
	char d = 'R';
	ll cnt = 0;
	int lef = 0, rig = 0;
	bool lefblock = 1, rigblock = 0;
	while (x < n-1){
		if (lefblock and rigblock)
			return cout << "Never\n", 0;
		cnt ++;
		if (s[x+1][y] == '.'){
			x ++;
			lef = y, rig = y;
			lefblock = 0, rigblock = 0;
			continue;
		}
		if (d == 'R' and y != rig){
			cnt += rig - y;
			y = rig;
		}
		if (d == 'L' and y != lef){
			cnt += y - lef;
			y = lef;
		}
		if (d == 'R'){
			if (y == m-1 or s[x][y+1] == '#'){
				d = 'L';
				rigblock = 1;
				continue;
			}
			if (s[x][y+1] == '+'){
				s[x][y+1] = '.';
				d = 'L';
				continue;
			}
			y ++;
			rig = max(rig, y);
			continue;
		}
		if (y == 0 or s[x][y-1] == '#'){
			d = 'R';
			lefblock = 1;
			continue;
		}
		if (s[x][y-1] == '+'){
			s[x][y-1] = '.';
			d = 'R';
			continue;
		}
		y --;
		lef = min(lef, y);
	}
	cout << cnt << endl;
}