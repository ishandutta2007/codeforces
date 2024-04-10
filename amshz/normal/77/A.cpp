# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 5e3 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
string base3(int a){
	string s = "";
	while (a){
		if (a % 3 == 0) s += '0';
		else if (a % 3 == 1) s += '1';
		else s += '2';
		a /= 3;
	}
	return s;
}
int fn1(string a){
	if (a == "Anka") return 0;
	if (a == "Chapay") return 1;
	if (a == "Cleo") return 2;
	if (a == "Troll") return 3;
	if (a == "Dracul") return 4;
	if (a == "Snowy") return 5;
	if (a == "Hexadecimal") return 6;
}

map <pii, bool> mp;
int n;
ll a, b, c;
vector <pii> vec;
 

void Solve(int ind){
	string s = base3(ind);
	ll x = 0;
	while (s.size() != 7) s += '0';
	vector <int> v1, v2, v3;
	for (int i = 0; i < s.size(); i ++){
		if (s[i] == '0') v1.push_back(i);
		else if (s[i] == '1') v2.push_back(i);
		else v3.push_back(i);
	}
	if (!v1.size() || !v2.size() || !v3.size()) return;
	
	for (int i = 0; i < v1.size(); i ++)
		for (int j = 0; j < v1.size(); j ++)
			if (mp[{v1[i], v1[j]}]) x ++;
		
	for (int i = 0; i < v2.size(); i ++)
		for (int j = 0; j < v2.size(); j ++)
			if (mp[{v2[i], v2[j]}]) x ++;
		
	for (int i = 0; i < v3.size(); i ++)
		for (int j = 0; j < v3.size(); j ++)
			if (mp[{v3[i], v3[j]}]) x ++;
		
	ll mn = inf, mx = 0;
	mn = min(mn, a / ll(v1.size()));
	mx = max(mx, a / ll(v1.size()));
	
	mn = min(mn, b / ll(v2.size()));
	mx = max(mx, b / ll(v2.size()));
	
	mn = min(mn, c / ll(v3.size()));
	mx = max(mx, c / ll(v3.size()));
	
	vec.push_back({mx - mn, x});
} 

bool cmp(pii i, pii j){
	if (i.F != j.F) return i.F < j.F;
	return i.S > j.S;
}
 

 
 
int main(){
	fast_io;
	
	cin >> n;
	while (n --){
		string x, y, z;
		cin >> x >> y >> z;
		mp[{fn1(x), fn1(z)}] = true;
	}
	cin >> a >> b >> c;
	
	for (int i = 0; i < pow(3, 7); i ++)
		Solve(i);
	
	sort(vec.begin(), vec.end(), cmp);
	
	cout << vec[0].F << sep << vec[0].S << endl;
	
	
	return 0;
}