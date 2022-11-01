# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 2e5 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
 

int n, nxt[xn], ans[xn], cnt;
string a; 
bool Mark[xn];
stack <int> st;
 
 
int main(){
	fast_io;
	
	cin >> n >> a;
	
	for (int i = 0; i < n; i ++){
		if (Mark[i]) continue;
		int pnt = i;
		cnt ++;
		ans[pnt] = cnt;
		while (pnt < n){
			int last = pnt;
			for (int j = pnt + 1; j < n; j ++){
				if (!Mark[j] && a[j] >= a[pnt]){
					pnt = j;
					break;
				}
			}
			if (pnt == last) break;
			ans[pnt] = cnt;
			Mark[pnt] = true;
		}
	}
	
	cout << cnt << endl;
	for (int i = 0; i < n; i ++) cout << ans[i] << sep;
	cout << endl;
	
	
	return 0;
}