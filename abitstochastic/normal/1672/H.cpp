#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7; int N , Q , ans[_]; string str;
struct qry{int l , r , id;}; vector < qry > pot;

void divide(int l , int r , vector < qry > pot){
	if(l == r){
		for(auto t : pot) ans[t.id] = 1;
		return;
	}
	vector < qry > L , R , M; int mid = (l + r) >> 1;
	for(auto t : pot)
		if(t.r <= mid) L.push_back(t);
		else if(t.l >= mid + 1) R.push_back(t);
		else M.push_back(t);
	divide(l , mid , L); divide(mid + 1 , r , R);
	static int num[_] , cnt[_]; num[mid] = num[mid + 1] = cnt[mid] = cnt[mid + 1] = 0;
	for(int i = mid - 1 ; i >= l ; --i)
		if(str[i] != str[i + 1]){num[i] = num[i + 1]; cnt[i] = cnt[i + 1] + 1;}
		else{
			num[i] = num[i + 1] + (str[i] == '1' ? 1 : -1); cnt[i] = cnt[i + 1];
			if(abs(num[i]) < abs(num[i + 1])) ++cnt[i];
		}
	for(int i = mid + 2 ; i <= r ; ++i)
		if(str[i] != str[i - 1]){num[i] = num[i - 1]; cnt[i] = cnt[i - 1] + 1;}
		else{
			num[i] = num[i - 1] + (str[i] == '1' ? 1 : -1); cnt[i] = cnt[i - 1];
			if(abs(num[i]) < abs(num[i - 1])) ++cnt[i];
		}
	for(auto t : M){
		int ans = t.r - t.l + 1 - cnt[t.l] - cnt[t.r];
		int tl = num[t.l] , tr = num[t.r];
		if(1ll * tl * tr < 0){
			int dlt = min(abs(tl) , abs(tr)); ans -= dlt;
			tl += (tl < 0 ? 1 : -1) * dlt; tr += (tr < 0 ? 1 : -1) * dlt;
		}
		int pl = str[mid] == '1' ? 1 : -1 , pr = str[mid + 1] == '1' ? 1 : -1;
		ans -= (pl * tr < 0) || (pr * tl < 0) || (pr * pl < 0);
		::ans[t.id] = ans;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin >> N >> Q >> str;
	for(int i = 1 ; i <= Q ; ++i){
		int l , r; cin >> l >> r; --l; --r; pot.push_back((qry){l , r , i});
	}
	divide(0 , N - 1 , pot);
	for(int i = 1 ; i <= Q ; ++i) cout << ans[i] << endl;
	return 0;
}