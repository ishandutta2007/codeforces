# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 2e5+10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
string bin(int g){
	string s = "";
	while (g){
		if (g%2) s += '1';
		else s += '0';
		g /= 2;
	}
	return s;
}
int n, a[xn], cnt[xn];
string b[xn];
int fn1(int g, int x){
	string s = b[g];
	if (x > s.size()) return 0;
	if (s[x] == '1') return 1;
	return 0;
}



int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 0; i < n; i++) b[i] = bin(a[i]);
	
	for (int i = 0; i < 35; i++){
		for (int j = 0; j < n; j++) cnt[i] += fn1(j, i);
	}
	for (int i = 34; i >= 0; i--){
		//cout << cnt[i] << endl;
		if (cnt[i] != 1) continue;
		for (int j = 0; j < n; j++){
			if (fn1(j, i)){
				swap(a[0], a[j]);
				break;
			}
		}
		break;
	}
	for (int i = 0; i < n; i++) cout << a[i] << sep;
	cout << endl;
	
	
	return 0;
}