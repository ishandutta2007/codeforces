# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 1e5+10;
const int xm = 3e5+10;
const int SQ = 1000;
const ll inf = 1e9+10;

string a, abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int n, ans;
 
 
int main(){
	fast_io;
	
	cin >> a;
	n = a.size();
	
	for (int i = 0; i < 26; i++){
		int last = -1, t = 1;
		for (int j = 0; j < n; j++){
			if (a[j] != abc[i]) continue;
			if (last == -1) last = j;
			else if ((j-last)%2) t++, last = j;
		}
		ans = max(ans, t);
	}
	
	cout << ans << endl;
	return 0;
}