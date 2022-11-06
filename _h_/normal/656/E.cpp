#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
	cin.sync_with_stdio(0);
	int n;
	cin >> n;
	vector<vi> a(n,vi(n));
	function<int(int,int)> las = [&](int i, int j){
		cin >> a[i][j];
		i==n-1 ? i=0,++j : ++i;
		j==n ? 0 : las(i,j);
		return 1;
	};
	las(0,0);
	function<int(int,int,int)> f = [&](int k, int i, int j){
		a[i][k] = min(a[i][k], a[i][j] + a[k][j]);
		k==n-1 ? k=0,++i : ++k;
		i==n ? i=0,++j : 0;
		j==n ? 0 : f(k,i,j);
		return 0;
	};
	f(0,0,0);
	int ans = 0;
	function<int(int,int)> svar = [&](int i, int j){
		ans = max(ans, a[i][j]);
		i==n-1 ? i=0,++j : ++i;
		j == n ? 0 : svar(i,j);
		return 0;
	};
	svar(0,0);
	cout << ans << endl;
}