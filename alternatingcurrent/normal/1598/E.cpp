#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int n, m, q;
bool ban[1010][1010];
set<int> block[3030];
ll ans = 0;

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	rep(ind, n + m){
		int mni = (ind < n ? n - ind - 1 : 0);
		int mnj = (ind < n ? 0 : ind - n);
		int diff0 = (ind < n ? n - 1 - ind : n - ind);
		int mxi0 = min(n - 1, m - 1 + diff0);
		int mxj0 = mxi0 - diff0;
		int diff1 = (ind < n ? n - 1 - ind + 1 : n - ind - 1);
		int mxi1 = min(n - 1, m - 1 + diff1);
		int mxj1 = mxi1 - diff1;
		if(mxi1 + mxj1 > mxi0 + mxj0)
			mxi0 = mxi1, mxj0 = mxj1;
		int l = mni + mnj, r = mxi0 + mxj0;
		block[ind].insert(l - 1), block[ind].insert(r + 1);
		ans += 1LL * (r - l + 1) * (r - l) / 2;
	}
	ans += 1LL * n * m;
	rep(i, q){
		int x, y;
		cin >> x >> y;
		x--, y--;
		int mxind = y - x + n;
		if(ban[x][y]){
			ans++;
			for(int ind = mxind - 1; ind <= mxind; ind++){
				set<int>::iterator it = block[ind].find(x + y);
				set<int>::iterator pre = it, nxt = it;
				pre--, nxt++;
				ans -= 1LL * (x + y - *pre - 1) * (x + y - *pre - 2) / 2;
				ans -= 1LL * (*nxt - x - y - 1) * (*nxt - x - y - 2) / 2;
				block[ind].erase(it);
				ans += 1LL * (*nxt - *pre - 1) * (*nxt - *pre - 2) / 2;
			}
		} else {
			ans--;
			for(int ind = mxind - 1; ind <= mxind; ind++){
				block[ind].insert(x + y);
				set<int>::iterator it = block[ind].find(x + y);
				set<int>::iterator pre = it, nxt = it;
				pre--, nxt++;
				ans -= 1LL * (*nxt - *pre - 1) * (*nxt - *pre - 2) / 2;
				ans += 1LL * (x + y - *pre - 1) * (x + y - *pre - 2) / 2;
				ans += 1LL * (*nxt - x - y - 1) * (*nxt - x - y - 2) / 2;
			}
		}
		ban[x][y] ^= 1;
		cout << ans << endl;
	}
	return 0;
}