#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n, m;
vector<int> c[100100];
vector<ll> s[100100];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, n){
			c[i].resize(m);
			rep(j, m)
				cin >> c[i][j];
			s[i].resize(m);
			s[i][0] = c[i][0];
			for(int j = 1; j < m; j++)
				s[i][j] = s[i][j - 1] + c[i][j];
		}
		for(int i = 1; i < n; i++){
			ll sum = 0;
			rep(j, m)
				sum += s[i][j] - s[0][j];
			if(sum > 0){
				cout << 1 << " " << sum << endl;
				break;
			}
			if(sum < 0){
				cout << i + 1 << " " << -sum << endl;
				break;
			}
		}
	}
	return 0;
}