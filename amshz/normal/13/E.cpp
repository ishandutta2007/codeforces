# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <pii, int> ppp;
 
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
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}


int n, m, num[xn], ted, last, ptr;
ppp SQRT[xn];

void Update(int ind){
	int Start = max(1, ind * SQ), End = min(n, ind * SQ + SQ - 1);
	for (int i = End; i >= Start; i --){
		if (i + num[i] > End){
			SQRT[i] = {{num[i] + i, 1}, i};
			continue;
		}
		SQRT[i].A.A = SQRT[num[i] + i].A.A;
		SQRT[i].A.B = SQRT[num[i] + i].A.B + 1;
		SQRT[i].B = SQRT[num[i] + i].B;
	}
}
void GET(int ind){
	ptr = ind, last = ind, ted = 0;
	while (ptr <= n){
		last = SQRT[ptr].B;
		ted += SQRT[ptr].A.B;
		ptr = SQRT[ptr].A.A;
	}
	cout << last << sep << ted << endl;
}


int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> num[i];
	for (int i = 0; i <= n / SQ; i ++) Update(i);
	while (m --){
		int t, x, y;
		cin >> t;
		if (t == 0){
			cin >> x >> y;
			num[x] = y;
			Update(x / SQ);
		}
		else{
			cin >> x;
			GET(x);
		}
	}
	
	return 0;
}