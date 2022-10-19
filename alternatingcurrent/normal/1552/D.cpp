#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n;
int a[12];

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		bool ok = 0;
		for(int mask = 1; mask < (1 << n); mask++){
			for(int posmask = (1 << n) - 1; posmask >= 0; posmask = (posmask - 1) & mask){
				int res = 0;
				rep(i, n){
					if(mask & (1 << i)){
						if(posmask & (1 << i))
							res += a[i];
						else
							res -= a[i];
					}
				}
				if(res == 0){
					ok = 1;
					break;
				}
				if(!posmask)
					break;
			}
			if(ok)
				break;
		}
		if(ok)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	return 0;
}