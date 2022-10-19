#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int n, m;
int c[100100];
vector<int> cx[100100], cy[100100];
int ind(int x, int y){
	return x * m + y;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, n)
		rep(j, m)
			cin >> c[ind(i, j)]; 
	rep(i, n * m)
		cx[c[i]].push_back(i / m), cy[c[i]].push_back(i % m);
	ll ans = 0;
	rep(nowcol, 100001){
		sort(cx[nowcol].begin(), cx[nowcol].end());
		ll sum = 0;
		rep(i, (int)cx[nowcol].size()){
			ans += 1ll * cx[nowcol][i] * i - sum; 
			sum += cx[nowcol][i];
		}
		sort(cy[nowcol].begin(), cy[nowcol].end());
		sum = 0;
		rep(i, (int)cy[nowcol].size()){
			ans += 1ll * cy[nowcol][i] * i - sum; 
			sum += cy[nowcol][i];
		}
	}
	cout << ans << endl;
	return 0;
}