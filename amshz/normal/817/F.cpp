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
const int xn = 5e5+10;
const int xm = 5e5+10;
const int SQ = 500;
const int inf = 1e9+10;


int n, q[xn], s = 1, a[xn], b[xn], c[xn], d[xn], t;
pll num[xn];
vector <ll> vec;
map <ll, ll> mp, tab;
// mp : 2e5 -> 1e18,  tab : 1e18 -> 2e5


void update1(int l, int r, int x){
	for (int i = l; i <= r;){
		if (i%SQ == 0 && i+SQ-1 <= r){
			b[i/SQ] = x;
			c[i/SQ] = 0;
			d[i/SQ] = x*SQ;
			i += SQ;
		}
		else{
			d[i/SQ] = 0;
			for (int j = i-i%SQ; j <= i-i%SQ+SQ-1; j++){
				if (b[i/SQ] != -1) a[j] = b[i/SQ];
				else a[j] = (a[j] + c[i/SQ]) % 2;
				if (j >= l && j <= r) a[j] = x;
				d[i/SQ] += a[j];
			}
			c[i/SQ] = 0;
			b[i/SQ] = -1;
			i = i-i%SQ+SQ;
		}
	}
}
void update2(int l, int r){
	for (int i = l; i <= r;){
		if (i%SQ == 0 && i+SQ-1 <= r){
			if (b[i/SQ] != -1) b[i/SQ] = 1 - b[i/SQ];
			else c[i/SQ]++;
			d[i/SQ] = SQ - d[i/SQ];
			i += SQ;
		}
		else{
			d[i/SQ] = 0;
			for (int j = i-i%SQ; j <= i-i%SQ+SQ-1; j++){
				if (b[i/SQ] != -1) a[j] = b[i/SQ];
				else a[j] = (a[j] + c[i/SQ]) % 2;
				if (j >= l && j <= r) a[j] = 1 - a[j];
				d[i/SQ] += a[j];
			}
			c[i/SQ] = 0;
			b[i/SQ] = -1;
			i = i-i%SQ+SQ;
		}
	}
}
int MEX(){
	int sm = 0;
	for (int i = 0; i < s/SQ+2; i++){
		if (d[i] == SQ) continue;
		for (int j = i*SQ; j <= i*SQ+SQ-1; j++){
			if (j == 0) continue;
			int val;
			if (b[i] != -1) val = b[i];
			else val = (a[j] + c[i]) % 2;
			if (val == 0) return j;
		}
	}
	return s-1;
}

 
int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> q[i] >> num[i].F >> num[i].S;
	
	for (int i = 0; i < n; i++) vec.pb(num[i].F), vec.pb(num[i].F-1), vec.pb(num[i].S+1), vec.pb(num[i].S);
	vec.pb(1);
	sort(vec.begin(), vec.end());
	
	for (int i = 0; i < vec.size(); i++){
		if (i > 0 && vec[i] == vec[i-1]) continue;
		if (vec[i] == 0) continue;
		mp[s] = vec[i];
		tab[vec[i]] = s;
		s++;
	}
	for (int i = 0; i <= 1e5; i++) b[i] = -1;
	
	for (int i = 0; i < n; i++){
		num[i].F = tab[num[i].F], num[i].S = tab[num[i].S];
		if (q[i] == 1) update1(num[i].F, num[i].S, 1);
		else if (q[i] == 2) update1(num[i].F, num[i].S, 0);
		else update2(num[i].F, num[i].S);
		ll ans = mp[MEX()];
		cout << ans << endl;
	}
	
		
	return 0;
}