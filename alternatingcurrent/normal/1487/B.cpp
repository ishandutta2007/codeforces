#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n, k;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> k;
		k--;
		if(n % 2 == 0) cout << (k % n + 1) << endl;
		else {
			long long num = 1LL * k / (n / 2) * (n / 2 + 1) + 1LL * (k % (n / 2));
			cout << (num % n + 1) << endl;
		}
	}
	return 0;
}