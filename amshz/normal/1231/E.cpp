# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 2e5+10;
const int xm = 2e5+10;
const int SQ = 1000;
const int sq = 1e3+10;
const int inf = 1e9+10;
 
int qq, n, pnt;
string a, b, s, t;
 
bool check(){
	s = a, t = b;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	for (int i = 0; i < a.size(); i++) if (s[i] != t[i]) return false;
	return true;
}
 
 
void Solve(){
	cin >> n >> a >> b;
	if (!check()){
		cout << -1 << endl;
		return;
	}
	int ans = n;
	for (int k = 0; k < n; k++){
		pnt = 0;
		for (int i = k; i < n; i++){
			while (pnt < n && a[pnt] != b[i]) pnt++;
			if (pnt < n) ans = min(ans, n - i + k - 1);
			else break;
			pnt++;
		}
	}
	cout << ans << endl;
}
 
 
int main(){
	fast_io;
	
	cin >> qq;
	
	while (qq--) Solve();
	
	return 0;
}