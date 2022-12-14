#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 500 + 10;

char s[maxn][maxn];
int a[maxn][maxn];
int x[] = {1, 0, -1, 0};
int y[] = {0, 1, 0, -1};

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
			s[i][j] = '0';
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> s[i][j];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			a[i][j] = (s[i][j] == '1');
			for (int z = 0; z < 4; z ++)
				a[i][j] &= (s[i + x[z]][j + y[z]] == '1');
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	}
	ll answer = 0;
	for (int dwn = 3; dwn <= n; dwn ++){
		for (int lef = 1; lef <= m; lef ++){
			for (int rig = lef + 2; rig <= m; rig ++){
				int lo = 0, hi = dwn - 1;
				while (hi - lo > 1){
					int mid = (lo + hi) >> 1;
					if (a[dwn - 1][rig - 1] - a[dwn - 1][lef] - a[mid][rig - 1] + a[mid][lef] >= k)
						lo = mid;
					else
						hi = mid;
				}
				answer += lo;
			}
		}
	}
	cout << answer << endl;
}