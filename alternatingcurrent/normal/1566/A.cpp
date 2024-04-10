#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n, s;
	int t;
	cin >> t;
	while(t--){
		cin >> n >> s;
		cout << s / (n - (n + 1) / 2 + 1) << endl;
	}
	return 0;
}