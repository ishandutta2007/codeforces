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
const int xn = 1e6+10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

int qq, n;
string a;
vector <pair <string, int> > vec;



int main(){
	fast_io;
	
	cin >> qq;
	while (qq--){
		cin >> n >> a;
		vec.clear();
		for (int k = 1; k <= n; k ++){
			string b = "";
			for (int i = k - 1; i < n; i ++) b += a[i];
			if ((n + k) % 2 == 0)for (int i = k - 2; i >= 0; i --) b += a[i];
			else for (int i = 0; i < k - 1; i ++) b += a[i];
			vec.push_back({b, k});
		}
		string ans = vec[0].F;
		int ind = vec[0].S;
		for (int i = 1; i < vec.size(); i ++){
			if (vec[i].F < ans){
				ans = vec[i].F;
				ind = vec[i].S;
			}
		}
		cout << ans << endl << ind << endl;
	}
	
	
	return 0;
}