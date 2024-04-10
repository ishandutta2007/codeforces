#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n, m;
int ans = 0;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> m;
		ans = 0;
		for(int i = 30; i >= 0; i--){
//			cout << i << " := " << ((n >> i) << i) + ((1 << i) - 1) << endl;
			if((n | ((1 << i) - 1)) <= m){
//				cout << i << ": " << (n xor (1 << i)) << endl;
				if((n xor (1 << i)) <= m){
					ans |= (1 << i);
					n ^= (1 << i);
				} else {
					ans |= ((1 << i) - 1);
					break;
				}
			}
		}
		if(n <= m)
			cout << ans + 1 << endl;
		else
			cout << "0" << endl;
	}
	return 0;
}