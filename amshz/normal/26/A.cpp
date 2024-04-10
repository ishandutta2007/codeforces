# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 3e3+10;
const int xm = 5e5+10;
const int SQ = 320;
const int inf = 1e9+10;


int n;
bool p[xn];
vector <int> prime;

bool fn1(int x){
	int ans = 0;
	for (int i = 0; i < prime.size(); i++){
		if (x%prime[i] == 0) ans++;
	}
	return (ans == 2);
}
 
 
int main(){
	fast_io;
	
	cin >> n;
	for (int i = 2; i <= n; i++){
		if (p[i]) continue;
		prime.pb(i);
		for (int j = 2; j <= n/i; j++) p[i*j] = true;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans += fn1(i);
	
	cout << ans << endl;
	

		
	return 0;
}