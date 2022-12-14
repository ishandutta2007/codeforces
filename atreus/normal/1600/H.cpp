#include <bits/stdc++.h>
using namespace std;

#define ios				ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define all(x)			x.begin(), x.end()
#define pb				push_back
#define mp				make_pair

typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
const int maxn = 1e6 + 10;
const int inf = 1e9 + 10;
const int mod = 1e9 + 7;

int n, k;
pii p[maxn], sh[maxn];
vector<int> gd;
int bd, bsh;

pii get(pii a, pii b){
	return mp(b.second - a.second, b.first - a.first);
}

ldb dist(int a, int b){
	ldb x = abs(p[a].first - p[b].first);
	ldb y = abs(p[a].second - p[b].second);
	return sqrt(x * x + y * y);
}

bool equal(int a, int b){
	return 1ll * sh[a].first * sh[b].second == 1ll * sh[b].first * sh[a].second;
}

bool cmp(int a, int b){
	if(p[a].first == p[b].first)
		return p[a].second < p[b].second;
	return p[a].first < p[b].first;
}

void solve(){
	sort(all(gd), cmp);
	ldb L = dist(gd.front(), bd);
	ldb R = dist(gd.back(), bd);
	ldb line = dist(gd.front(), gd.back());
	if(k == bd){
		ldb ans = line + min(L, R);
		cout << fixed << setprecision(6) << ans << '\n';
		exit(0);
	}
	int id;
	for(int i = 0; i < gd.size(); i ++){
		if(gd[i] == k){
			id = i;
			break;
		}
	}
	ldb K = dist(gd[id], bd);
	ldb ans = line + K + min(L, R);
	for(int r = id; r < gd.size(); r ++){
		ldb tp;
		ldb RD = 0;
		if(r + 1 < gd.size()){
			RD = dist(gd[r], gd[r + 1]);
		}
		tp = line - RD;
		ldb res = min(dist(gd[id], gd[r]) + L, dist(gd.front(), gd[id]) + dist(gd[r], bd));
		tp += res;
		RD = 0;
		if(r + 1 < gd.size()){
			RD = dist(gd[r + 1], bd);
		}
		tp += min(R, RD);
		ans = min(ans, tp);
	}
	for(int l = id; l >= 0; l --){
		ldb tp;
		ldb LD = 0;
		if(l){
			LD = dist(gd[l], gd[l - 1]);
		}
		tp = line - LD;
		ldb res = min(dist(gd[l], gd[id]) + R, dist(gd[id], gd.back()) + dist(gd[l], bd));
		tp += res;
		LD = 0;
		if(l){
			LD = dist(gd[l - 1], bd);
		}
		tp += min(L, LD);
		ans = min(ans, tp);
	}
//	cout << "1 : " << ans << '\n';
//	ans = min(ans, line + L + min(RK, R) - RD);
//	cout << "2 : " << ans << '\n';
//	cout << line - LD << ' ' << ' ' << R << ' ' << LK << " " << L << '\n';
//	ans = min(ans, line + R + min(LK, L) - LD);
//	cout << "3 : " << ans << '\n';
	cout << fixed << setprecision(6) << ans << '\n';
	exit(0);
}

int main(){
	ios;
	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		cin >> p[i].first >> p[i].second;
	}
	if(n == 3){
		bd = 3;
		gd.pb(1);
		gd.pb(2);
		solve();
	}
	for(int i = 2; i <= n; i ++){
		sh[i] = get(p[1], p[i]);
	}
	if(!equal(2, 3) and !equal(3, 4) and !equal(2, 4)){
		bd = 1;
		for(int i = 2; i <= n; i ++)
			gd.pb(i);
		solve();
	}
	if(equal(2, 3)){
		bsh = 2;
	}
	else{
		bsh = 4;
	}
	gd.pb(1);
	for(int i = 2; i <= n; i ++){
		if(equal(i, bsh)){
			gd.pb(i);
		}
		else{
			bd = i;
		}
	}
	solve();
}