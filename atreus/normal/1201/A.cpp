#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 4e5 + 10;
const int inf = 1e9;

int a[maxn][7];

int main(){
	ios_base::sync_with_stdio (false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			a[j][(int)(s[j] - 'A')] ++;
	}
	int answer = 0;
	for (int i = 0; i < m; i++){
		int pnt;
		cin >> pnt;
		int mx = 0;
		for (int j = 0; j < 5; j++)
			mx = max(mx, a[i][j]);
		answer += pnt * mx;
	}
	cout << answer << endl;
}