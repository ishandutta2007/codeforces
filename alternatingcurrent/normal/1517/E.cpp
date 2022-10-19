#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll Mod = 998244353;

int T;
int n, alln;
ll alla[200200];
ll a[200200];
ll suf[200200];
ll diff[200200];
ll initsum = 0LL;
ll ans = 0LL;

void getans(bool okbeg, bool okend){
//	cout << "----------" << okbeg << " " << okend << "-----------" << endl;
	suf[n] = 0;
	for(int i = n - 1; i >= 0; i--) suf[i] = suf[i + 1] + a[i];
	diff[0] = a[0];
	for(int i = 1; i < n; i++) diff[i] = diff[i - 1] + ((i & 1) ? -a[i] : a[i]);
	ll pre = 0;
	rep(i, n + 1){
		int lb = 0, ub = n;
		while(lb <= ub){
			int mid = (lb + ub) >> 1;
			if(i + mid * 2 > n) ub = mid - 1;
			else{
				ll sumdiff = (((i + mid * 2) > 0) ? diff[i + mid * 2 - 1] : 0) - (i ? diff[i - 1] : 0);
				ll sum = initsum - pre + ((i & 1) ? -sumdiff : sumdiff) + suf[i + mid * 2];
//				cout << i << " " << mid << " " << sum << endl;
				if(sum > 0) lb = mid + 1;
				else ub = mid - 1;
			}
		}
//		cout << i << ": " << ub << ": ";
		if(okbeg || i){
			ans += (ub + 1);
//			cout << "+=" << ub + 1 << " ";
			if(!okend && (i + ub * 2 == n) && i != n) ans--;
		} else {
			if(ub >= 0) ans++;
		}
		pre += a[i];
	}
	if(!okbeg && !okend){
		pre = a[0] + a[1];
		for(int i = 2; i < n - 1; i++){
			if(pre > suf[i]) ans++;
			pre += a[i];
		} 
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		ans = 0;
		cin >> alln;
		rep(i, alln) cin >> alla[i];
		if(alln == 1) cout << "1" << endl;
		else if(alln == 2){
			if(alla[0] == alla[1]) cout << "1" << endl;
			else cout << "2" << endl;
		} else {
			n = alln;
			rep(i, n) a[i] = alla[i];
			initsum = 0;
			getans(0, 0);
			n = alln - 2;
			initsum = a[0] - a[1];
			rep(i, n) a[i] = alla[i + 2];
			getans(1, 0);
			n = alln - 2;
			initsum = a[alln - 2] - a[alln - 1];
			rep(i, n) a[i] = alla[i];
			getans(0, 1);
			if(alln >= 4){
				n = alln - 4;
				initsum = a[0] - a[1] + a[alln - 2] - a[alln - 1];
				rep(i, n) a[i] = alla[i + 2];
				getans(1, 1);
			}
			cout << ans % Mod << endl;
		}
	}
	return 0;
}