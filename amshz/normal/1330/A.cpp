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
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 2e2 + 10;
const int xm = 2e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int qq, n, a[xn], x, ted, last;
bool Mark[xn];

int main(){
	fast_io;
	
	cin >> qq;
	while (qq --){
		cin >> n >> x;
		for (int i = 0; i < n; i ++) cin >> a[i];
		memset(Mark, false, sizeof Mark);
		for (int i = 0; i < n; i ++) Mark[a[i]] = true;
		ted = 0;
		for (int i = 1; i <= 201; i ++){
			if (!Mark[i]) ted ++;
			last = i;
			if (ted == x + 1) break;
		}
		cout << last - 1 << endl;
	}
	
	return 0;
}