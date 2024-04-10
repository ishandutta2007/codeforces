#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int Q;
int n;
int a, b, c, d;

int main(){
	ios::sync_with_stdio(false);
	cin >> Q;
	while(Q--){
		cin >> n >> a >> b >> c >> d;
		bool ok = 0;
		rep(a00, 2){
			a -= a00, b -= a00;
			rep(a01, 2){
				b -= a01, c -= a01;
				rep(a10, 2){
					c -= a10, d -= a10;
					rep(a11, 2){
						d -= a11, a -= a11;
						if(a >= 0 && a <= n - 2 && b >= 0 && b <= n - 2 && c >= 0 && c <= n - 2 && d >= 0 && d <= n - 2){
							ok = 1;
							break;
						}
						d += a11, a += a11;
					}
					if(ok) break;
					c += a10, d += a10; 
				}
				if(ok) break;
				b += a01, c += a01;
			}
			if(ok) break;
			a += a00, b += a00;
		}
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}