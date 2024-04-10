# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 2e5+10;
const int xm = 2e5+2;
const int xk = 1e5+2;
const int SQ = 450;
const int SQ2 = 4090;
const int SQ3 = 75;
const int inf = 1e9+10;
 

int a[xn], b[xn], n, c[xn], d[xn], q;

void Build(){
	for (int i = 0; i <= xm; i++) b[i] = 0, a[i] = 1;
}
void update(int l, int r, int x){
	l += xk, r += xk;
	for (int i = l; i <= r;){
		if (i%SQ == 0 && i+SQ-1 <= r) b[i/SQ] = x, c[i/SQ] = 0, i += SQ;
		else{
			for (int j = i-i%SQ; j <= i-i%SQ+SQ-1; j++){
				if (j > xm) break;
				if (j >= l && j <= r) a[j] = x;
				else if (b[i/SQ] != 0) a[j] = b[i/SQ];
				else if (c[i/SQ]%2) a[j] = -a[j];
			}
			b[i/SQ] = 0;
			c[i/SQ] = 0;
			i = i-i%SQ+SQ;
		}
	}
}
void update2(int l, int r){
	l += xk, r += xk;
	for (int i = l; i <= r;){
		if (i%SQ == 0 && i+SQ-1 <= r){
			if (b[i/SQ] != 0) {
				if (b[i/SQ] == 1) b[i/SQ] = -1;
				else b[i/SQ] = 1;
				c[i/SQ] = 0;
			}
			else c[i/SQ]++;
			i += SQ;
		}
		else{
			for (int j = i-i%SQ; j <= i-i%SQ+SQ-1; j++){
				if (j > xm) break;
				if (b[i/SQ] != 0) a[j] = b[i/SQ];
				else if (c[i/SQ]%2) a[j] = -a[j];
				if (j >= l && j <= r) a[j] = -a[j];
			}
			b[i/SQ] = 0;
			c[i/SQ] = 0;
			i = i-i%SQ+SQ;
		}
	}
}
void Query(int x, char y){
	if (y == '>'){
		if (x >= 0){
			update(-xk, -x-1, 1);
			update(x+1, xk, -1);
			
		}
		else{
			update(-xk, x, 1);
			update(-x, xk, -1);
			update2(x+1, -x-1);
		}
	}
	else{
		if (x <= 0){
			update(-x+1, xk, 1);
			update(-xk, x-1, -1);
		}
		else{
			update(x, xk, 1);
			update(-xk, -x, -1);
			update2(-x+1, x-1);
		}
	}
}
void get(){
	for (int i = 0; i < n; i++){
		int s = d[i] + xk, f = d[i];
		if (b[s/SQ] != 0) f *= b[s/SQ];
		else{
			f *= a[s];
			if (c[s/SQ]%2) f = -f;
		}
		cout << f << sep;
	}
	cout << endl;
}

 
 
int main(){
	fast_io;
	
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> d[i];
	
	Build();
	
	while (q--){
		int x;
		char y;
		cin >> y >> x;
		Query(x, y);
		
		
	}
	
	get();
	
	
	return 0;
}