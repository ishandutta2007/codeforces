# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const int md = 1e9;
const int xn = 1e5 + 10;
const int xm = 1e6 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
 
 
ll power(ll a, ll b){return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll jaam(int a, int b){return (a + b) % md;}
ll menha(int a, int b){return (a - b + md) % md;}
ll zarb(int a, int b){return (1LL * a * b) % md;}
 

int n;
string name;
map <string, int> mp;
set <string> st;
vector <pair <int, string> > vec;

bool cmp(pair <int, string> i, pair <int, string> j){
	if (i.F != j.F) return i.F > j.F;
	return i.S < j.S;
}
 
int main(){
	fast_io;
	
	cin >> name >> n;
	for (int i = 0; i < n; i ++){
		string a, b, c, d, e;
		cin >> a >> b >> c >> d;
		string dd = "";
		if (b == "posted"){
			cin >> e;
			for (int j = 0; j < d.size() - 2; j ++) dd += d[j];
			d = dd;
			if (a == name || d == name) mp[a] += 15, mp[d] += 15;
			st.insert(a), st.insert(d);
		}
		else if (b == "commented"){
			cin >> e;
			for (int j = 0; j < d.size() - 2; j ++) dd += d[j];
			d = dd;
			if (a == name || d == name) mp[a] += 10, mp[d] += 10;
			st.insert(a), st.insert(d);
		}
		else{
			for (int j = 0; j < c.size() - 2; j ++) dd += c[j];
			c = dd;
			if (a == name || c == name) mp[a] += 5, mp[c] += 5;
			st.insert(a), st.insert(c);
		}
	}
	
	for (string x : st){
		vec.push_back({mp[x], x});
	}
	sort(vec.begin(), vec.end(), cmp);
	
	for (int i = 0; i < vec.size(); i ++) if (vec[i].S != name) cout << vec[i].S << endl;
	
	
	return 0;
}