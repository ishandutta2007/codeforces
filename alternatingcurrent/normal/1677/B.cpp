#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n, m; 
string s;
int sum[1000100];
int remval[1000100];
int ans[1000100];
bool colok[1000100];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> m >> s;
		rep(i, m)
			remval[i] = 0; 
		sum[0] = 0;
		rep(i, n * m)
			sum[i + 1] = (sum[i] + (s[i] - '0'));
		rep(r, n * m){
			int l = max(0, r - m + 1);
			if(sum[r + 1] - sum[l])
				remval[r % m]++;
			ans[r] = remval[r % m];
		}
		int colans = 0;
		rep(i, m)
			colok[i] = 0;
		rep(i, n * m){
			if(!colok[i % m] && s[i] - '0')
				colok[i % m] = 1, colans++;
			ans[i] += colans;
		}
		rep(i, n * m)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}