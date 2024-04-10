#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
const double EPS = 1e-6;
inline bool Equal(double a, double b){
	return (a - b) < EPS && (b - a) < EPS;
}

int T;
int n;
int a[77];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		if(n == 1){
			cout << "0" << endl;
			continue;
		}
		int ans = n;
		rep(i, n)
			rep(j, i){
				double d = 1.0 * (a[i] - a[j]) / (i - j);
				int cnt = 0;
				rep(k, n){
					cnt += !Equal(a[k], a[j] + d * (k - j));
				}
				ans = min(ans, cnt);
			}
		cout << ans << endl;
	}
	return 0;
}