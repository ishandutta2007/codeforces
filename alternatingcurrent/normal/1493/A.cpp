#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		int k, n;
		cin >> n >> k;
		int st = (k + 1) / 2;
		cout << n - st << endl;
		for(int i = st; i < k; i++) cout << i << " ";
		for(int i = k+1; i <= n; i++) cout << i << " ";
		cout << endl;
	}
	return 0;
}