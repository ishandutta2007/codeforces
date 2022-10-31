# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 4+10;
const int xm = 1e2+10;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

bool cmp(pair <int, pii> i, pair <int, pii> j){
	return i.F > j.F;
}

int qq, n, m, a[xn][xm], c[4];
pair <int, pii> b[xn*xm];

bool check(){
	int t = 1;
	for (int i = 1; i < 4; i++) t += (b[i].S.S == b[0].S.S);
	if (t != 2){
		return true;
	}
	int x = -1, y = -1;
	t = 0;
	for (int i = 1; i < 4; i++){
		if (b[i].S.S == b[0].S.S) continue;
		if (x == -1){
			t++;
			x = b[i].S.F, y = b[i].S.S;
			continue;
		}
		if (y == b[i].S.S) t++;
	}
	if (t != 2){
		return true;
	}
	c[0] = c[1] = c[2] = c[3] = 0;
	for (int i = 0; i < 4; i++){
		for (int j = i+1; j < 4; j++){
			if (b[i].S.S != b[j].S.S) continue;
			int d = abs(b[i].S.F - b[j].S.F);
			c[d]++;
		}
	}
	c[1] += c[3];
	if (c[1] != c[2] || c[1] != 1){
		return true;
	}
	return false;
}

void Solve(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
	int s = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			b[s].F = a[i][j];
			b[s].S = {i, j};
			s++;
		}
	}
	
	sort(b, b + n*m, cmp);
	
	if (n < 4){
		int ans = 0;
		for (int i = 0; i < n; i++) ans += b[i].F;
		cout << ans << endl;
		return;
	}
	int t = 1;
	for (int i = 1; i < 4; i++) t += (b[i].S.S == b[0].S.S);
	if (t != 2){
		cout << b[0].F + b[1].F + b[2].F + b[3].F << endl;
		return;
	}
	int x = -1, y = -1;
	t = 0;
	for (int i = 1; i < 4; i++){
		if (b[i].S.S == b[0].S.S) continue;
		if (x == -1){
			t++;
			x = b[i].S.F, y = b[i].S.S;
			continue;
		}
		if (y == b[i].S.S) t++;
	}
	if (t != 2){
		cout << b[0].F + b[1].F + b[2].F + b[3].F << endl;
		return;
	}
	c[0] = c[1] = c[2] = c[3] = 0;
	for (int i = 0; i < 4; i++){
		for (int j = i+1; j < 4; j++){
			if (b[i].S.S != b[j].S.S) continue;
			int d = abs(b[i].S.F - b[j].S.F);
			c[d]++;
		}
	}
	c[1] += c[3];
	if (c[1] != c[2] || c[1] != 1){
		cout << b[0].F + b[1].F + b[2].F + b[3].F << endl;
		return;
	}
	int ans = b[0].F + b[1].F + b[2].F + b[3].F + b[4].F, mx = 0;
	
	for (int i = 3; i >= 0; i--){
		swap(b[i], b[4]);
		if (check()){
			swap(b[i], b[4]);
			ans -= b[i].F;
			mx = max(mx, ans);
			break;
		}
		swap(b[i], b[4]);
	}
	if (n*m == 5){
		cout << mx << endl;
		return;
	}
	swap(b[4], b[5]);
	ans = b[0].F + b[1].F + b[2].F + b[3].F + b[4].F;
	
	for (int i = 3; i >= 0; i--){
		swap(b[i], b[4]);
		if (check()){
			swap(b[i], b[4]);
			ans -= b[i].F;
			mx = max(mx, ans);
			break;
		}
		swap(b[i], b[4]);
	}
	cout << mx << endl;
}


int main(){
	fast_io;
	
	cin >> qq;
	while (qq--){
		Solve();
	}
	
	
	return 0;
}