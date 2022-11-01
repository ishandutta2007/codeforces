# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, ll> pii;
 
# define A first
# define B second
# define endl '\n'
# define sep ' '
# define pb push_back
# define InTheNameOfGod ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 2e5 + 10;
const int xm = 3e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int qq, n, cnt[2][xm], ted;
string a, b, c;
bool flag;

 
int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		cin >> n >> a >> b;
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; i ++) cnt[0][a[i] - 'a'] ++, cnt[1][b[i] - 'a'] ++;
		flag = true;
		for (int i = 0; i < 26; i ++) flag &= (cnt[0][i] == cnt[1][i]);
		if (!flag){
			cout << "NO" << endl;
			continue;
		}
		flag = false;
		for (int i = 0; i < 26; i ++) flag |= (cnt[0][i] > 1);
		if (flag){
			cout << "YES" << endl;
			continue;
		}
		ted = 0;
		while (a.size() > 2){
			c = "";
			for (int i = 0; i < b.size(); i ++){
				if (b[i] == a[0]) ted += i;
				else c += b[i];
			}
			b = c;
			c = "";
			for (char d : a) if (d != a[0]) c += d;
			a = c;
		}
		if (a[0] == b[ted % 2]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}