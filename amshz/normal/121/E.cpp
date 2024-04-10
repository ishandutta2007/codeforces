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
const int xn = 1e5+10;
const int xm = 4e1+10;
const int xk = 1e4+10;
const int SQ = 320;
const int sq = 5e2+10;
const ll inf = 1e18+10;

int n, m, a[xn], b[sq], c[sq][xk];
vector <int> lucky;

bool check(int x){
	while (x){
		if (x%10 != 7 && x%10 != 4) return false;
		x /= 10;
	}
	return true;
}

void update(int l, int r, int x){
	for (int i = l; i <= r;){
		if (i%SQ == 0 && i+SQ-1 <= r){
			b[i/SQ] += x;
			i += SQ;
		}
		else{
			c[i/SQ][a[i]]--;
			a[i] += x;
			c[i/SQ][a[i]]++;
			i++;
		}
	}
}
int get(int l, int r){
	int ans = 0;
	for (int i = l; i <= r;){
		if (i%SQ == 0 && i+SQ-1 <= r){
			for (int j = 0; j < lucky.size(); j++){
				if (lucky[j]-b[i/SQ] < 0) continue;
				ans += c[i/SQ][lucky[j]-b[i/SQ]];
			}
			i += SQ;
		}
		else{
			if (check(a[i] + b[i/SQ])) ans++;
			i++;
		}
	}
	return ans;
}

 
int main(){
	fast_io;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 1; i <= 1e4; i++) if (check(i)) lucky.pb(i);
	
	for (int i = 0; i < n; i++) c[i/SQ][a[i]]++;
	
	while (m--){
		string s;
		cin >> s;
		if (s == "add"){
			int x, y, z;
			cin >> x >> y >> z;
			x--, y--;
			update(x, y, z);
		}
		else{
			int x, y;
			cin >> x >> y;
			x--, y--;
			cout << get(x, y) << endl;
		}
	}
	
	return 0;
}