#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 400010, LOG=20;

int n, m, k, u, v, x, y, a, b, ans;
string s, t, p;

int solve(){
	cin>>s>>t>>p;
	map<char, int> mp;
	for (char ch:t) mp[ch]++;
	for (char ch:s) if (!(mp[ch]--)) kill("No")
	for (char ch:p) mp[ch]--;
	for (auto p:mp) if (p.second>0) kill("No")
	int ptr=0;
	for (int i=0; i<t.size(); i++) if (ptr<s.size() && s[ptr]==t[i]) ptr++;
	if (ptr<s.size()) kill("No")
	
	kill("Yes")
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) solve();
	
	return 0;
}