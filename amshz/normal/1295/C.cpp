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
const int xn = 1e6+10;
const int xm = 3e5+10;
const int SQ = 1000;
const int sq = 1e3+10;
const int inf = 1e9+10;

ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

int qq;

string s, t;
map <char, bool> mp;


 
int main(){
	fast_io;
	
	
	cin >> qq;
	while (qq--){
		cin >> s >> t;
		mp.clear();
		for (int i = 0; i < s.size(); i++) mp[s[i]] = true;
		bool fl1 = false;
		for (int i = 0; i < t.size(); i++) if (!mp[t[i]]) fl1 = true;
		
		if (fl1){
			cout << -1 << endl;
			continue;
		}
		map <char, vector <int> > vec;
		
		for (int i = 0; i < s.size(); i++) vec[s[i]].pb(i);
		
		int ans = 1;
		int last = -1;
		
		for (int i = 0; i < t.size(); i++){
			char c = t[i];
			int l = -1, r = vec[c].size(), mid;
			while (r-l > 1){
				mid = (l+r)/2;
				if (vec[c][mid] <= last) l = mid;
				else r = mid;
			}
			if (r == vec[c].size()){
				ans++;
				//cout << c << sep << last << endl;
				last = vec[c][0];
				continue;
			}
			last = vec[c][r];
		}
		cout << ans << endl;
	}
	
	
	return 0;
}