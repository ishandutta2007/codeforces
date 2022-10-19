#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, q;
bool a[100100];
int cnt1 = 0;

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	rep(i, n) cin >> a[i];
	rep(i, n) cnt1 += a[i];
	while(q--){
		int tp, k;
		cin >> tp >> k;
		if(tp == 1){
			k--;
			a[k] ^= 1;
			if(a[k]) cnt1++;
			else cnt1--;
		} else {
			if(cnt1 >= k) cout << "1" << endl;
			else cout << "0" << endl;
		}
	}
	return 0;
}