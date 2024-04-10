#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200040
#define INF 101111111111111
using namespace std;
vector<ll> d[N];
string a[N];
map<string, ll> words;
bool was[N];
ll sz = 0;
void dfs(ll v){
	sz++;
	was[v] = true;
	for(auto i : d[v]) if(!was[i]) dfs(i);
}
int main(){
	FAST;
	ll n;
	cin >> n;
	for(ll i =1;i<=n;i++){
		cin >> a[i];
		sort(itr(a[i]));
		if(words[a[i]]!=0){
			--i, n--;
			continue;
		}
		else words[a[i]] = i;
		for(ll j =0;j<a[i].size()-1;j++){
			if(a[i][j] == a[i][j+1]) continue;
			ll verta = a[i][j]-'a'+1;
			ll vertb = i+26;
			d[verta].pb(vertb);
			d[vertb].pb(verta);
		} //lastletter
			ll verta = a[i][a[i].size()-1]-'a'+1;
			ll vertb = i+26;
			d[verta].pb(vertb);
			d[vertb].pb(verta);
	}
	ll compres = 0;
	for(ll i = 1;i<=26;i++){
		if(!was[i]){
			sz = 0;
			dfs(i);
			if(sz > 1) compres++;
		}
	}
	cout << compres << endl;
}