# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 3e5+10;
const int xm = 1e2+10;
const int SQ = 1000;
const int sq = 1e3+10;
const int inf = 1e9+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

int q, cnt[30][xn];
string a, abc = "abcdefghijklmnopqrstuvwxyz";




int main(){
	fast_io;
	
	cin >> a >> q;
	for (int i = 0; i < 26; i++){
		int t = 0;
		for (int j = 0; j < a.size(); j++){
			if (a[j] == abc[i]) t++;
			cnt[i][j] = t;
		}
	}
	while (q--){
		int l, r;
		cin >> l >> r;
		l--, r--;
		if (l == r){
			cout << "Yes" << endl;
			continue;
		}
		
		int t = 0;
		for (int i = 0; i < 26; i++){
			if (l == 0){
				if (cnt[i][r]) t++;
			}
			else{
				if (cnt[i][r] - cnt[i][l-1]) t++;
			}
		}
		if (t > 2){
			cout << "Yes" << endl;
			continue;
		}
		if (a[l] != a[r]){
			cout << "Yes" << endl;
			continue;
		}
		cout << "No" << endl;
	}
	
	
	return 0;
}