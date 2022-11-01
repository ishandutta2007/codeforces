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
const int xn = 2e2 + 10;
const int xm = 2e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int qq, n, m;
char a[xn][xn];


int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		cin >> n >> m;
		for (int i = 0; i < n; i ++){
			for (int j = 0; j < m; j ++){
				if (i == 0 && j == 0) a[i][j] = 'W';
				else a[i][j] = 'B';
			}
		}
		for (int i = 0; i < n; i ++){
			for (int j = 0; j < m; j ++) cout << a[i][j];
			cout << endl;
		}
	}
	
	return 0;
}