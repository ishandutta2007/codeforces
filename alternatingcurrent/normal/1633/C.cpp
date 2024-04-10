#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll hc, dc, hm, dm;
ll k, d, a;

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> hc >> dc >> hm >> dm;
		cin >> k >> d >> a;
		bool ok = 0;
		for(int i = 0; i <= k; i++){
			ll hc1 = hc + i * a, dc1 = dc + (k - i) * d;
			ok |= (hm + dc1 - 1) / dc1 <= (hc1 + dm - 1) / dm;
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
	return 0;
}