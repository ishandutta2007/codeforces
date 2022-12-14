#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 300 + 10;
const int inf = 2e9;

int a[maxn][maxn], dp[maxn][maxn][maxn], pd[maxn][maxn][maxn];
int tp, tu, td;

int dis(int x, int y){
	if (x == y)
		return tp;
	if (x < y)
		return tu;
	return td;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, t;
	cin >> n >> m >> t;
	cin >> tp >> tu >> td;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	set<pair<int,int>> s;
	int answer = inf, l, r, u, d;
	for (int k = 1; k <= m; k++){
		for (int j = k+1; j <= m; j++){
			s.clear();
			int lazy = 0;
			for (int i = 1; i <= n; i++){
				dp[k][j][i] = dp[k][j-1][i] + dis(a[i][j], a[i][j-1]);
				if (i != 1 and j - k + 1 >= 3){
					lazy += dis(a[i][k], a[i-1][k]) + dis(a[i-1][j], a[i][j]);
					auto it = s.lower_bound(make_pair(t - dp[k][j][i] - lazy, 0));
					if (it != s.end() and (*it).second == i-1)
						it ++;
					if (it != s.end() and (*it).first + dp[k][j][i] + lazy - t < answer){
						answer = (*it).first + dp[k][j][i] + lazy - t;
						l = k, r = j;
						u = (*it).second, d = i;
					}
					it = s.lower_bound(make_pair(t - dp[k][j][i] - lazy, 0));
					if (it != s.begin())
						it --;
					if (it != s.begin() and (*it).first == i-1)
						it --;
					if (it != s.begin()){
						if (t - (*it).first - dp[k][j][i] - lazy < answer){
							answer = t - (*it).first - dp[k][j][i] - lazy;
							l = k, r = j;
							u = (*it).second, d = i;
						}
					}
				}
				pd[k][j][i] = pd[k][j-1][i] + dis(a[i][j-1], a[i][j]);
				s.insert({pd[k][j][i] - lazy, i});
			}
		}
	}
	cerr << answer << endl;
	cout << u << " " << l << " " << d << " " << r << endl;
}