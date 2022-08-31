#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  3e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m, lps[N], aut[N][26];
vector <vll> dp;
string s, t;

void LPS(){
	lps[0] = 0;
	for(int i = 1; i < m; i++){
		int j = lps[i - 1];
		while(j > 0 && t[i] != t[j]) j = lps[j - 1];
		lps[i] = j + (t[i] == t[j]);
	}
}

void automaton(){
	t += '#';
	LPS();
	for(int i = 0; i <= m; i++){
		for(int j = 0; j < 26; j++){
			if(i > 0 && j + 'a' != t[i]) aut[i][j] = aut[lps[i - 1]][j];
			else aut[i][j] = i + (j + 'a' == t[i]);
		}
	}
}

ll mem(int i, int j){
	if(i == n) return j == m;
	ll &ans = dp[i][j];
	if(ans != -1) return ans;
	if(s[i] == '?'){
		for(int c = 0; c < 26; c++){
			ans = max(ans, mem(i + 1, aut[j][c]) + (j == m));
		}
	} else ans = mem(i + 1, aut[j][s[i] - 'a']) + (j == m);
	return ans;
}

void solve(){
	cin >> s >> t;
	n = s.size();
	m = t.size();
	automaton();
	dp = vector <vll> (n + 1, vll(m + 1, -1));
	deb1(mem(0, 0));
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}