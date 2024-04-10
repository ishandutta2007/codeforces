# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
# define A first
# define B second
# define endl '\n'
# define sep ' '
# define pb push_back
# define InTheNameOfGod ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 2e5 + 10;
const int xm = 2e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int qq, n, a[xn], b[xn], ps[2][xn];

int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; i ++) cin >> a[i];
		for (int i = 1; i <= n; i ++) cin >> b[i];
		for (int i = 1; i <= n; i ++){
			ps[0][i] = ps[0][i - 1];
			ps[1][i] = ps[1][i - 1];
			if (a[i] == 1) ps[0][i] ++;
			if (a[i] == -1) ps[1][i] ++;
		}
		bool flag = true;
		for (int i = n; i > 0; i --){
			if (a[i] == b[i]) continue;
			if (a[i] < b[i]) flag &= (ps[0][i - 1] > 0);
			else flag &= (ps[1][i - 1] > 0);
		}
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}