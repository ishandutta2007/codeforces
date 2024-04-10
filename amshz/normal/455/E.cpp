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
const int xn = 1e5 + 10;
const int xm = 2e1 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}


int n, num[xn], qq, SQRT[sq][xn], part[xn], x, y, ans;

void Update(int k){
	int start = k - k % SQ, End = min(start + SQ, n + 1);
	int L = 0, R = n + 1;
	for (int i = start; i < End; i ++){
		if (i == k || i == 0) continue;
		x = part[k] - part[i] - i * num[i] + num[i] + k * num[k] - num[k];
		y = num[k] - num[i];
		if (y == 0){
			if (x <= 0) continue;
			else return;
		}
		if (y > 0) L = max(L, x / y + 1);
		else R = min(R, (x + y - 1) / y - 1);
	}
	for (int i = L; i <= R; i ++){
		if (SQRT[k / SQ][i]) break;
		SQRT[k / SQ][i] = k;
	}
}
int Get(int k, int i, int j){return (k + i - j - 1) * num[k] + part[k] - part[j + 1];}

void Solve(int i, int j){
	ans = inf;
	for (int k = j - i + 1; k <= j;){
		if (k % SQ == 0 && k + SQ - 1 <= j) ans = min(ans, Get(SQRT[k / SQ][j - i], i, j)), k += SQ;
		else ans = min(ans, Get(k, i, j)), k ++;
	}
	cout << ans << endl;
}


int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> num[i];
	for (int i = n; i >= 0; i --) part[i] = part[i + 1] + num[i];
	for (int i = n; i >= 1; i --) Update(i); 
	cin >> qq;
	while (qq --){
		int i, j;
		cin >> i >> j;
		Solve(i, j);
	}
	
	return 0;
}