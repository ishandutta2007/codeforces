#include<bits/stdc++.h>
using namespace std;

int main(){
	int N; cin >> N; int L = 1 , R = 4e6 + N;
	while(L < R){
		int mid = (L + R) >> 1;
		cout << "? " << mid << endl; int x; cin >> x;
		x == 1 ? R = mid : L = mid + 1;
	}
	int ans = L;
	for(int i = 2 ; i <= N ; ++i){
		cout << "? " << (L - 1) / i << endl; int x; cin >> x;
		if(x) ans = min(ans , (L - 1) / i * x);
	}
	cout << "! " << ans << endl;
	return 0;
}