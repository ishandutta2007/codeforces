#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int t;
int a, b;

int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> a >> b;
		int na = a;
		int ans = 0x3f3f3f3f;
		rep(i, 50){
			int nb = b + i;
			if(nb == 1) continue;
			int cnt = i;
			na = a;
			while(na){
				cnt++;
				na /= nb;
			}
			ans = min(ans, cnt);
		}
		cout << ans << endl;
	}
	return 0;
}