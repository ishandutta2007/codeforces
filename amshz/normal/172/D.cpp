# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 1e7 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll jaam(ll a, ll b){
	return (a + b + 10 * md) % md;
}
ll menha(ll a, ll b){
	return (a - b + 10 * md) % md;
}

ll l, r, ans[xn], res;
 
 
int main(){
	fast_io;
	
	cin >> l >> r;
	r += l;
	
	for (int i = 1; i * i <= 1e7; i ++)
		for (int j = 1; j * i * i <= 1e7; j ++)
			ans[j * i * i] = j;
	
	for (int i = l; i < r; i ++) res += ans[i];
	
	cout << res << endl;
	
	
	return 0;
}