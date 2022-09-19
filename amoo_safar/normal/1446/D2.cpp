// nemibinam invara kasi mesle khodemono !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;
const int SQ = 400;

int cnt[N], a[N];

int fs[N + N], mk[N + N];

int nx[N], ps[N], pr[N];
int wh[N];
vector<int> V[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int mx = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]] ++;
		V[a[i]].pb(i);
		mx = max(mx, cnt[a[i]]);
	}
	int c = 0, la = 0;
	for(int i = 1; i <= n; i++){
		if(cnt[i] == mx) c++, la = i;
	}
	if(c >= 2) return cout << n << '\n', 0;
	int ans = 0;
	for(int q = 1; q <= n; q++){
		if(q == la) continue;
		if(cnt[q] < SQ) continue;
		int sm = n;
		fs[sm] = 0;
		mk[sm] = q;
		for(int i = 1; i <= n; i++){
			if(a[i - 1] == la) sm --;
			if(a[i - 1] == q) sm ++;
			if(mk[sm] == q){
				ans = max(ans, i - fs[sm]);
			} else {
				mk[sm] = q;
				fs[sm] = i;
			}
		}
	}
	///////////////////////////////
	memset(fs, 0, sizeof fs);
	memset(mk, 0, sizeof mk);


	nx[n] = n;
	for(int i = n - 1; i >= 0; i--){
		nx[i] = nx[i + 1];
		if(a[i] == la) nx[i] = i;
	}
	pr[0] = -1;
	for(int i = 1; i <= n; i++){
		pr[i] = pr[i - 1];
		if(a[i - 1] == la) pr[i] = i - 1;
	}
	ps[0] = 0;
	for(int i = 1; i <= n; i++) ps[i] = ps[i - 1] + (a[i - 1] == la ? 1 : 0);

	for(int q = 1; q <= n; q++){
		if(q == la) continue;
		if(cnt[q] >= SQ) continue;
		if(cnt[q] == 0) continue;
		//debug(q);
		//	if(q != 2) continue;
		int sm = n;
		fs[sm] = 0;
		mk[sm] = q;
		int al = cnt[q];
		int lv = -1;
		for(auto x : V[q]){
			if(lv != -1) wh[lv] = x;
			lv = x;
		}
		wh[lv] = n;

		lv = -1;
		for(auto x : V[q]){
			int po = x;
			for(int j = 0; j <= al; j++){
				if(pr[po] <= lv) break;
				po = pr[po] + 1;
				if(mk[sm - ps[po]] != q){
					//debug(po);
					//debug(sm);
					mk[sm - ps[po]] = q;
					fs[sm - ps[po]] = po;
				}
				po --;
			}


			sm ++;
			
			po = x + 1;
			for(int j = 0; j <= al; j++){
				if(nx[po] >= wh[x]) break;
				po = nx[po];
				//debug(po);
				if(mk[sm - ps[po]] == q){
					ans = max(ans, po - fs[sm - ps[po]]);
				}
				po ++;
			}

			lv = x;
		}
		if(mk[sm - ps[n]] == q){
			ans = max(ans, n - fs[sm - ps[n]]);
		}
		/*
		for(int i = 1; i <= n; i++){
			if(a[i - 1] == la) sm --;
			if(a[i - 1] == q) sm ++;
			if(mk[sm] == q){
				ans = max(ans, i - fs[sm]);
			} else {
				mk[sm] = q;
				fs[sm] = i;
			}
		}
		*/	
	}




	cout << ans << '\n';
	return 0;
}