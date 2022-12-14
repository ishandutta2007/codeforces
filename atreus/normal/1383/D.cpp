#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 250 + 20;

int a[maxn][maxn], b[maxn][maxn], c[maxn], r[maxn], markc[maxn*maxn], markr[maxn*maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			r[i] = max(r[i], a[i][j]);
			c[j] = max(c[j], a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
		markr[r[i]] = 1;
	for (int i = 1; i <= m; i++)
		markc[c[i]] = 1;
	int x = 0, y = 0;
	vector<pair<int,int>> fil;
	for (int i = n*m; i >= 1; i--){
		if (!markr[i] and !markc[i])
			continue;
		if (markr[i])
			x ++;
		if (markc[i])
			y ++;
		b[x][y] = i;
		fil.push_back({x,y});
	}
	int now = n*m;
	for (int i = 1; i < fil.size(); i++){
		int x = fil[i].first, y = fil[i].second;
		int px = fil[i-1].first, py = fil[i-1].second;
		if (x != px){
			for (int j = y-1; j >= 1; j--){
				while (markr[now] or markc[now])
					now --;
				b[x][j] = now --;
			}
		}
		if (y != py){
			for (int j = x-1; j >= 1; j--){
				while (markr[now] or markc[now])
					now --;
				b[j][y] = now --;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cout << b[i][j] << " \n"[j == m];
}