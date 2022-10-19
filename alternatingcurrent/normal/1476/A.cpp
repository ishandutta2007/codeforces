#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int t;
int n, k;

int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n >> k;
		if(k >= n) cout << (k + n - 1) / n << endl;
		else cout << 1 + (bool)(n % k != 0) << endl;
	}
	return 0;
}